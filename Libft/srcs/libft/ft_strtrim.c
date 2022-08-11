/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchee <nchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:07:54 by nchee             #+#    #+#             */
/*   Updated: 2022/07/12 11:29:16 by nchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_totrim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start] && ft_totrim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_totrim(s1[end - 1], set))
		end--;
	dest = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!dest)
		return (0);
	i = 0;
	while (start < end)
		dest[i++] = s1[start++];
	dest[i] = 0;
	return (dest);
}
