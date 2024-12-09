/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:06:14 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/09 21:44:24 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	is_int(t_data data)
{
	int	num;

	num = va_arg(data.vars, int);
	if (num < 0)
		data.format.arg.sign = SIG_NEG;
	else if (num >= 0 && data.format.pos == TRUE)
		data.format.arg.sign = SIG_POS;
	else if (num >= 0 && data.format.space == TRUE)
		data.format.arg.sign = SIG_SPC;
	if (num < 0)
		data.format.arg.str = uns_itoa_base(-num, data.format.base);
	else
		data.format.arg.str = uns_itoa_base(num, data.format.base);
	if (data.format.width < (int)ft_strlen(data.format.arg.str))
		data.format.width = (int)ft_strlen(data.format.arg.str);
	return (data);
}

t_data	is_char(t_data data)
{
	char	c;

	c = va_arg(data.vars, char);
	data.format.arg.str = ft_strdup(&c);
	return (data);
}

t_data	is_str(t_data data)
{
	char	*str;

	str = va_arg(data.vars, char *);
	data.format.arg.str = ft_strdup(str);
	return (data);
}

t_data	is_uns(t_data data)
{
	data.format.arg.str = uns_itoa_base(va_arg(data.vars, unsigned int)\
	, data.format.base);
	if (data.format.width < (int)ft_strlen(data.format.arg.str))
		data.format.width = (int)ft_strlen(data.format.arg.str);
	return (data);
}
