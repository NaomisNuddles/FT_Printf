/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:22:06 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 21:44:29 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fsplit(char **res, size_t j)
{
	while (res[j])
		free(res[j++]);
	free(res);
	return (0);
}

char	**ft_split(const char *src, char c)
{
	size_t	i;
	size_t	j;
	char	**res;

	j = 0;
	while (src && *src)
	{
		if (*src && *src++ != c && (*src == c || !*src))
			j++;
	}
	res = ft_calloc(8, j + 1);
	while (res && j > 0 && j-- && --src)
	{
		while (*src && *src == c)
			src--;
		i = ft_strlen(src);
		while (*src && *src != c)
			src--;
		src++;
		res[j] = ft_substr(src, 0, ft_strlen(src) - i + 1);
		if (!res[j])
			return (fsplit(res, j + 1));
	}
	return (res);
}
