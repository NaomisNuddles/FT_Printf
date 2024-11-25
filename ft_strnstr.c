/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:48 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:58:38 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *prb, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!prb[0])
		return ((char *)src);
	while (src && prb && i < n && src[i])
	{
		j = 0;
		while (prb[j] && src[i + j] && src[i + j] == prb[j] && i + j < n)
			j++;
		if (!prb[j])
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}
