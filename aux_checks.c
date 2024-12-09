/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:56:50 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/09 21:28:47 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	flags_check(char c, t_data data)
{
	if (c == 43)
		data.format.pos = TRUE;
	else if (c == 45)
		data.format.neg = TRUE;
	else if (c == 32)
		data.format.space = TRUE;
	else if (c == 48)
		data.format.zero = TRUE;
	else if (c == 39)
		data.format.quote = TRUE;
	else if (c == 35)
		data.format.hash = TRUE;
	else
		data.format.flags = FILLED;
	if (data.format.pos == TRUE)
		data.format.space = FALSE;
	if (data.format.neg == TRUE)
		data.format.zero = FALSE;
	return (data);
}

t_data	type_check(char c, t_data data)
{
	if (c == 'd' || c == 'i')
		data.format.type = INT;
	else if (c == 'c')
		data.format.type = CHAR;
	else if (c == 's')
		data.format.type = STR;
	else if (c == 'p')
	{
		data.format.type = UNS;
		data.format.hash = TRUE;
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		data.format.type = UNS;
	else
		data.format.type = NONE;
	if (c == 'o')
		data.format.base = OCTA;
	else if (c == 'p' || c == 'x')
		data.format.base = HEXMI;
	else if (c == 'X')
		data.format.base = HEXMA;
	return (data);
}

t_data	build_check(t_data data)
{
	if (data.format.type == INT)
		data = is_int(data);
	else if (data.format.type == CHAR)
		data = is_char(data);
	else if (data.format.type == STR)
		data = is_str(data);
	else if (data.format.type == UNS)
		data = is_uns(data);
	else if (data.format.type == NONE)
		data = reset_data(data);
	return (data);
}
