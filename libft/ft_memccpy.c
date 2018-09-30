/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:50:04 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 12:13:16 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	*ptr;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			ptr = dst1 + i + 1;
		i++;
	}
	return (ptr);
}
