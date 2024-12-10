/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:29:36 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 20:02:05 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	i;
	int	j;

	i = printf("o:%05%$", 1);
	printf("\n");
	j = ft_printf("f:%05%$", 1);
	ft_printf("\n");
	ft_printf("sizeo:%d$\n", i);
	ft_printf("sizef:%d$\n", j);
	return (0);
}
