/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:33:38 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/09 14:28:43 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*csrc;
	char		*cdst;
	size_t		space;
	size_t		dl;

	csrc = src;
	cdst = dst;
	space = dstsize;
	while (space-- && *cdst)
		cdst++;
	dl = cdst - dst;
	space = dstsize - dl;
	if (space == 0)
		return (dl + ft_strlen((char*)csrc));
	while (*csrc && space-- != 1)
		*cdst++ = *csrc++;
	while (*csrc)
		csrc++;
	*cdst = '\0';
	return (dl + (csrc - src));
}
