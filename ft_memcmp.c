/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:34 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:54:07 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	size_t	i;

	i = 0;
	if (!src1 || !src2 || n > ((size_t)1 << 63) - 1)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)src1)[i] != ((unsigned char *)src2)[i])
			return (((unsigned char *)src1)[i] - ((unsigned char *)src2)[i]);
		i++;
	}
	return (0);
}
