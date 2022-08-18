/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchee <nchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:43:46 by nchee             #+#    #+#             */
/*   Updated: 2022/08/18 11:55:11 by nchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	feedback(int sig)
{
	(void)sig;
	ft_printf("SUCCESS: String received by server\n");
	exit (0);
}

void	client_sighandler(int pid, char *string)
{
	int		bit_count;
	int		byte_count;
	char	c;

	byte_count = 0;
	while (string[byte_count] - 1)
	{
		c = string[byte_count];
		bit_count = 8;
		while (--bit_count >= 0)
		{
			if (c && ((c >> bit_count) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(60);
		}
		byte_count++;
	}
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, feedback);
	if (argc != 3 || !ft_strisdigit(argv[1]) || !*argv[2])
	{
		ft_printf("ERROR: Wrong Format\n");
		ft_printf("TRY: ./client <PID Number> <String>");
	}
	else
		client_sighandler(ft_atoi(argv[1]), argv[2]);
}
