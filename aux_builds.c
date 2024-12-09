/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_builds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:58:20 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/09 21:48:19 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	format_build(t_data data)
{
	
	return (data);
}

t_data	arg_build(t_data data)
{
	while (data.format.flags == EMPTY)
	{
		data.index++;
		data = flags_check(data.str[data.index], data);
	}
	if (ft_isdigit(data.str[data.index]))
		data.format.width = ft_atoi(&data.str[data.index]);
	while (ft_isdigit(data.str[data.index]))
		data.index++;
	if (data.str[data.index] == 46)
		data.format.width = ft_atoi(&data.str[data.index + 1]);
	data.index++;
	while (ft_isdigit(data.str[data.index]))
		data.index++;
	type_check(data.str[data.index], data);
	data.index++;
	data = build_check(data);
	return (format_build(data));
}
