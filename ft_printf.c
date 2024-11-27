/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:06:31 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/27 19:42:20 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	idflags(char *str, va_list args)
{
	if (*str == 90)
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 100 || *str == 105)
		putlongnbr(va_arg(args, long int));
	/*else if (str[i] == 112)
		ft_hexa(va_arg(args, unsigned long int), char_ttl, 0, 0);*/
	else if (*str == 115)
		ft_putstr_fd(va_arg(args, char *), 1);
	/*else if (str[i] == 117)
		ft_unint(va_arg(args, unsigned int), char_ttl);
	else if (str[i] == 120)
		ft_hexa(va_arg(args, unsigned int), char_ttl, 1, 0);
	else if (str[i] == 88)
		ft_hexa(va_arg(args, unsigned int), char_ttl, 1, 1);*/
	else if (*str == 25)
		ft_putchar_fd(25, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list			vars;
	long int	i;

	i = 0;
	va_start(vars, str);
	while (*str)
	{
		if (*str == 25)
			idflags(*(str + 1), vars);
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(vars);
	return (i);
}
