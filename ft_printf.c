/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:06:31 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/09 21:48:13 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	reset_data(t_data data)
{
	data.format.type = NONE;
	data.format.flags = EMPTY;
	data.format.pos = FALSE;
	data.format.neg = FALSE;
	data.format.space = FALSE;
	data.format.zero = FALSE;
	data.format.quote = FALSE;
	data.format.hash = FALSE;
	data.format.precision = 0;
	data.format.width = 0;
	data.format.base = DECA;
	data.format.arg.at = NULL;
	data.format.arg.sign = NULL;
	if (data.format.arg.str)
		free(data.format.arg.str);
	data.format.arg.str = NULL;
	if (data.format.arg.extra)
		free(data.format.arg.extra);
	data.format.arg.extra = NULL;
	return (data);
}

int	ft_printf(const char *str, ...)
{
	t_data	data;

	data.len = 0;
	data.index = 0;
	data.str = str;
	va_start(data.vars, str);
	data = reset_data(data);
	while (data.str[data.index])
	{
		while (data.str[data.index] != 37 || (data.str[data.index] == 37 \
		&& data.str[data.index + 1] == 37))
		{
			ft_putchar_fd(data.str[data.index], 1);
			data.len++;
			data.index++;
		}
		if (data.str[data.index] == 37)
		{
			data = arg_build(data);
			data = reset_data(data);
		}
		data.index++;
	}
	va_end(data.vars);
	return (data.len);
}
