/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:29:36 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 15:22:36 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	i;
	int	j;

	i = printf("o %.2d ", -1);
	ft_printf("\n");
	j = ft_printf("f %.2d ", -1);
	ft_printf("\n");
	ft_printf("sizeo:%d$\n", i);
	ft_printf("sizef:%d$\n", j);
	return (0);
}
