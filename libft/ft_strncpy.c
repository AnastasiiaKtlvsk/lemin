/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:55:05 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 12:11:36 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char			*dest1;
	const char		*src1;
	int				i;

	i = -1;
	dest1 = dest;
	src1 = src;
	while (++i < (int)n && src1[i])
		dest1[i] = src1[i];
	while (i < (int)n)
		dest1[i++] = '\0';
	return (dest1);
}
