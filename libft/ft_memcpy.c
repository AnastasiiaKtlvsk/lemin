/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:18:30 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/26 16:18:33 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src1;
	char		*dst1;
	int			i;

	i = -1;
	src1 = src;
	dst1 = dst;
	while (++i < (int)n)
		dst1[i] = src1[i];
	return (dst);
}
