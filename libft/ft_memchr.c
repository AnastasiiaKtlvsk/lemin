/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:38:31 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/26 17:38:34 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;
	int				i;

	s2 = (unsigned char*)s;
	c2 = (unsigned char)c;
	i = -1;
	while (++i < (int)n)
		if (*s2++ == c2)
			return (--s2);
	return (NULL);
}
