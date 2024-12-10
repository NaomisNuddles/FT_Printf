/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:01:07 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 19:12:18 by nleandro         ###   ########.fr       */
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
	data->format->precision = -1;
	data->format->width = 0;
	data->format->base = NULL;
	data->format->arg->at_s = NULL;
	data->format->arg->prc = NULL;
	data->format->arg->str = NULL;
	data->format->arg->extra = NULL;
	return (data);
}

t_data	*free_build(t_data *data)
{
	if (data->format->width)
		free(data->format->arg->extra);
	if (data->format->precision)
		free(data->format->arg->prc);
	if (data->format->type != NONE)
		free(data->format->arg->str);
	return (data);
}

void	free_data(t_data *data)
{
	free(data->format->arg);
	free(data->format);
	free(data);
}
