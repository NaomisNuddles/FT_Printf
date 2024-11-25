/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:26 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:42:59 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	size_t	i;

	i = 0;
	while (src && i <= ft_strlen(src))
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}
