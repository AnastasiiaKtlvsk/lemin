/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:19:07 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 12:10:44 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = (char*)s + ft_strlen((char*)s);
	if (c == '\0')
		return (s2);
	while (*s2 != c)
	{
		if (*s2 == *s)
			return (NULL);
		s2--;
	}
	return (s2);
}
