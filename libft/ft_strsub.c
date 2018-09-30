/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:28:50 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/01 16:28:51 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*c;
	int			ic;

	if (!s)
		return (NULL);
	ic = 0;
	if ((c = (char*)ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (ic < (int)len && s[start])
			c[ic++] = s[start++];
		c[ic] = '\0';
		return (c);
	}
	return (NULL);
}
