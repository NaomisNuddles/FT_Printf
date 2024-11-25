/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:52 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 19:44:34 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!src || !dst || n > ((size_t)1 << 63) - 1)
		return (dst);
	while (n-- > 0)
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}
