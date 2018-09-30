/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:08:59 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/08 14:51:23 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdest;
	char	*temp;
	int		i;

	csrc = (char*)src;
	cdest = (char*)dst;
	i = -1;
	if ((temp = (char*)ft_memalloc(sizeof(char) * len)))
	{
		while (++i < (int)len)
			temp[i] = csrc[i];
		i = -1;
		while (++i < (int)len)
			cdest[i] = temp[i];
	}
	return (cdest);
}
