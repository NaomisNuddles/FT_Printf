/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:50:14 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:43:20 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	i;

	i = ft_strlen(src) + 1;
	while (src && i-- > 0)
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
	}
	return (0);
}
