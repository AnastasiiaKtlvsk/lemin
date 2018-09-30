/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:35:08 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/03 14:19:37 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		if (*s11 == '\0' || *s22 == '\0')
			n = 0;
		s11++;
		s22++;
	}
	return (0);
}
