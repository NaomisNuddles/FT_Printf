/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_builds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:52 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/15 15:39:41 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_build(t_data *data)
{
	if (data->format->type == INT)
		is_int(data, va_arg(data->vars, int));
	else if (data->format->type == CHAR)
		is_char(data, va_arg(data->vars, int));
	else if (data->format->type == STR)
		is_str(data, va_arg(data->vars, char *));
	else if (data->format->type == UNS)
		is_uns(data, va_arg(data->vars, unsigned int));
	else if (data->format->type == PTR)
		is_ptr(data, va_arg(data->vars, unsigned long int));
	else if (data->format->type == CEN)
	{
		reset_data(data);
		is_char(data, 37);
	}
	else if (data->format->type == NONE)
	{
		while (data->str[data->index] != 37)
			data->index--;
	}
}

void	precision_build(t_data *data)
{
	size_t	size;

	size = (size_t)data->format->precision - ft_strlen(data->format->arg->str);
	if (ft_strlen(data->format->base) == 8)
		size -= 1;
	data->format->arg->prc = ft_calloc(1, size + 1);
	if (!data->format->arg->prc)
		return ;
	data->format->arg->prc = ft_memset(data->format->arg->prc, 48, size);
}

void	width_build(t_data *data)
{
	size_t	size;

	size = (size_t)data->format->width - \
	(ft_strlen(data->format->arg->at_s) + ft_strlen(data->format->arg->str) \
	+ ft_strlen(data->format->arg->prc));
	if (data->format->type == CHAR && !data->format->arg->str[0])
		size -= 1;
	data->format->arg->extra = ft_calloc(1, size + 1);
	if (!data->format->arg->extra)
		return ;
	data->format->arg->extra = ft_memset(data->format->arg->extra, 32, size);
	if (data->format->zero == TRUE && (data->format->type == INT || \
	data->format->type == UNS))
		data->format->arg->extra = \
		ft_memset(data->format->arg->extra, 48, size);
}
