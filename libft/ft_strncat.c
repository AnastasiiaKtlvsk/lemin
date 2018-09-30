/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:24:57 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/27 17:24:59 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int		i1;
	int		i2;

	i1 = 0;
	while (s1[i1])
		i1++;
	i2 = 0;
	while (s2[i2] && i2 < (int)n)
		s1[i1++] = s2[i2++];
	s1[i1] = '\0';
	return (s1);
}
