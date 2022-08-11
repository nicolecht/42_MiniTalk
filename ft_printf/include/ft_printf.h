/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchee <nchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:39 by nchee             #+#    #+#             */
/*   Updated: 2022/07/18 14:10:01 by nchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <libft.h>

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
void	ft_putstr(char *str);
int		ft_printptr(unsigned long long ptr);
void	ft_putptr(uintptr_t num);
int		ft_ptrlen(uintptr_t num);
int		ft_printnbr(int n);
int		ft_printunsigned(unsigned int n);
char	*ft_utioa(unsigned int n);
int		ft_numlen(unsigned int n);
int		ft_printhex(unsigned int num, const char format);
void	ft_puthex(unsigned int num, const char format);
int		ft_hexlen(unsigned int num);
int		ft_printpercent(void);

#endif