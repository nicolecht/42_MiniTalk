/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchee <nchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:10:37 by nchee             #+#    #+#             */
/*   Updated: 2022/07/12 11:29:04 by nchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && i + j < len)
			{
				j++;
				if (!to_find[j])
					return ((char *)str + i);
			}
		}
		i++;
	}
	return (0);
}
