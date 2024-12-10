/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:32 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 13:06:42 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*is_int(t_data *data, int num)
{
	if (num < 0)
		data->format->arg->sign = SIG_NEG;
	else if (num >= 0 && data->format->pos == TRUE)
		data->format->arg->sign = SIG_POS;
	else if (num >= 0 && data->format->space == TRUE)
		data->format->arg->sign = SIG_SPC;
	if (num < 0)
		data->format->arg->str = uns_itoa_base(-num, data->format->base);
	else
		data->format->arg->str = uns_itoa_base(num, data->format->base);
	if (data->format->width < (int)(ft_strlen(data->format->arg->str) + \
	ft_strlen(data->format->arg->sign)))
		data->format->width = 0;
	return (data);
}

t_data	*is_char(t_data *data, int num)
{
	char	c;

	c = num;
	data->format->arg->str = ft_strdup(&c);
	return (data);
}

t_data	*is_str(t_data *data, char *str)
{
	if (data->format->precision)
		data->format->arg->str = ft_substr(str, 0, \
		(size_t)data->format->precision);
	else
		data->format->arg->str = ft_strdup(str);
	if (data->format->width < (int)ft_strlen(data->format->arg->str))
		data->format->width = 0;
	return (data);
}

t_data	*is_uns(t_data *data, unsigned int val)
{
	if (data->format->hash == TRUE && ft_strlen(data->format->base) == 8)
		data->format->arg->at = PTR_OC;
	else if (data->format->hash == TRUE && ft_strlen(data->format->base) == 16 \
	&& data->format->base[10] == 'a')
		data->format->arg->at = PTR_HD;
	else if (data->format->hash == TRUE && ft_strlen(data->format->base) == 16 \
	&& data->format->base[10] == 'A')
		data->format->arg->at = PTR_HU;
	data->format->arg->str = uns_itoa_base(val, data->format->base);
	if (data->format->width < (int)(ft_strlen(data->format->arg->str) + \
	ft_strlen(data->format->arg->at)))
		data->format->width = 0;
	return (data);
}
