/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:26 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 20:36:59 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!src || n > ((size_t)1 << 63) - 1)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return ((void *)src + i);
		i++;
	}
	return (0);
}
