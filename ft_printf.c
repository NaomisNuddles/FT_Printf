/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:59 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 13:06:24 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*reset_data(t_data *data)
{
	data->format->type = NONE;
	data->format->flags = EMPTY;
	data->format->pos = FALSE;
	data->format->neg = FALSE;
	data->format->space = FALSE;
	data->format->zero = FALSE;
	data->format->quote = FALSE;
	data->format->hash = FALSE;
	data->format->precision = 0;
	data->format->width = 0;
	data->format->base = NULL;
	data->format->arg->at = NULL;
	data->format->arg->sign = NULL;
	data->format->arg->str = NULL;
	data->format->arg->extra = NULL;
	return (data);
}

static t_data	*data_test(t_data	*data)
{
	if (data->str[data->index] != 37 || (data->str[data->index] == 37 && \
		data->str[data->index + 1] == 37))
	{
		ft_putchar_fd(data->str[data->index], 1);
		data->len++;
		if (data->str[data->index] == 37)
			data->index++;
	}
	else if (data->str[data->index] == 37)
		data = print_build(reset_data(data));
	return (data);
}

static void	free_data(t_data *data)
{
	free(data->format->arg);
	free(data->format);
	free(data);
}

int	ft_printf(const char *str, ...)
{
	t_data	*data;
	int		len;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->format = malloc(sizeof(t_format));
	if (!data->format)
		return (0);
	data->format->arg = malloc(sizeof(t_arg));
	if (!data->format->arg)
		return (0);
	data->len = 0;
	data->index = 0;
	data->str = str;
	va_start(data->vars, str);
	while (data->index <= (int)ft_strlen(str))
	{
		data = data_test(data);
		data->index++;
	}
	va_end(data->vars);
	len = data->len;
	free_data(data);
	return (len);
}
