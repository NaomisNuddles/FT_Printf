/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:04:18 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 20:38:18 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *src, const char *prb)
{
	size_t	frt;
	size_t	lst;

	if (!src)
		return (0);
	frt = 0;
	lst = ft_strlen(src);
	while (src[frt] && ft_strchr(prb, src[frt]))
		frt++;
	while (lst > frt && ft_strchr(prb, src[lst - 1]))
		lst--;
	return (ft_substr(src, frt, lst - frt));
}
