/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_builds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:52 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 13:11:35 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*width_build(t_data *data)
{
	size_t	size;

	size = (size_t)data->format->width - \
	(ft_strlen(data->format->arg->at) + ft_strlen(data->format->arg->str) + \
	ft_strlen(data->format->arg->sign));
	data->format->arg->extra = ft_calloc(1, size + 1);
	if (!data->format->arg->extra)
		return (data);
	data->format->arg->extra = ft_memset(data->format->arg->extra, 32, size);
	if (data->format->zero == TRUE && (data->format->type == INT || \
	data->format->type == UNS))
		data->format->arg->extra = \
		ft_memset(data->format->arg->extra, 48, size);
	return (data);
}

static t_data	*format_build(t_data *data)
{
	if (data->format->width)
		data = width_build(data);
	data->len += (int)(ft_strlen(data->format->arg->at) + \
	ft_strlen(data->format->arg->str) + ft_strlen(data->format->arg->sign) + \
	ft_strlen(data->format->arg->extra));
	if (data->format->zero == FALSE && data->format->neg == FALSE)
		ft_putstr_fd(data->format->arg->extra, 1);
	ft_putstr_fd(data->format->arg->sign, 1);
	ft_putstr_fd(data->format->arg->at, 1);
	if (data->format->zero == TRUE)
		ft_putstr_fd(data->format->arg->extra, 1);
	ft_putstr_fd(data->format->arg->str, 1);
	if (data->format->neg == TRUE)
		ft_putstr_fd(data->format->arg->extra, 1);
	if (data->format->width)
		free(data->format->arg->extra);
	if (data->format->type != NONE)
		free(data->format->arg->str);
	return (data);
}

t_data	*print_build(t_data *data)
{
	while (data->format->flags == EMPTY)
	{
		data->index++;
		data = flags_check(data->str[data->index], data);
	}
	if (ft_isdigit(data->str[data->index]))
		data->format->width = ft_atoi(&data->str[data->index]);
	while (ft_isdigit(data->str[data->index]))
		data->index++;
	if (data->str[data->index] == 46)
	{
		data->format->precision = ft_atoi(&data->str[data->index + 1]);
		data->index++;
	}
	while (ft_isdigit(data->str[data->index]))
		data->index++;
	type_check(data->str[data->index], data);
	data = build_check(data);
	return (format_build(data));
}
