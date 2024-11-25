/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:22:40 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/25 10:22:42 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(1, ft_strlen(src) + 1);
	if (!str)
		return (0);
	while (src && f && src[i])
	{
		str[i] = f(i, src[i]);
		i++;
	}
	return (str);
}
