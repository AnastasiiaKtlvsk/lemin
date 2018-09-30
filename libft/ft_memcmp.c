/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:21:27 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 12:11:05 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	while (n > 0 && *src1 == *src2)
	{
		--n;
		src1++;
		src2++;
	}
	if (n == 0)
		return (0);
	else
		return (*src1 - *src2);
}
