/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:32 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/16 20:11:40 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_int(t_data *data, int num)
{
	if (num < 0)
		data->format->arg->at_s = SIG_NEG;
	else if (num >= 0 && data->format->pos == TRUE)
		data->format->arg->at_s = SIG_POS;
	else if (num >= 0 && data->format->space == TRUE)
		data->format->arg->at_s = SIG_SPC;
	if (num == 0 && data->format->precision == 0)
		data->format->arg->str = NULL;
	else if (num < 0)
		data->format->arg->str = uns_itoa_base(-num, data->format->base);
	else
		data->format->arg->str = uns_itoa_base(num, data->format->base);
}

void	is_char(t_data *data, int num)
{
	char	c;

	c = num;
	data->format->arg->str = ft_substr(&c, 0, 1);
}

void	is_str(t_data *data, char *str)
{
	if (!str && data->format->precision >= 0 && data->format->precision <= 5)
		data->format->arg->str = ft_strdup(str);
	else if (!str && (data->format->precision >= 6 || \
	data->format->precision == -1))
		data->format->arg->str = ft_strdup("(null)");
	else if (data->format->precision >= 0)
		data->format->arg->str = ft_substr(str, 0, \
		(size_t)data->format->precision);
	else
		data->format->arg->str = ft_strdup(str);
}

void	is_uns(t_data *data, unsigned int val)
{
	if (!val)
		data->format->arg->at_s = NULL;
	else if (data->format->hash == TRUE && ft_strlen(data->format->base) == 8)
		data->format->arg->at_s = PTR_OC;
	else if (data->format->hash == TRUE && ft_strlen(data->format->base) == 16 \
	&& data->format->base[10] == 'a')
		data->format->arg->at_s = PTR_HD;
	else if (data->format->hash == TRUE && ft_strlen(data->format->base) == 16 \
	&& data->format->base[10] == 'A')
		data->format->arg->at_s = PTR_HU;
	if (val == 0 && data->format->precision == 0)
		data->format->arg->str = NULL;
	else
		data->format->arg->str = uns_itoa_base(val, data->format->base);
}

void	is_ptr(t_data *data, unsigned long int val)
{
	if (!val)
		data->format->arg->str = ft_strdup("(nil)");
	else
	{
		data->format->arg->str = unsl_itoa_base(val, data->format->base);
		data->format->arg->at_s = PTR_HD;
	}
}
