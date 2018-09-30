/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:22:43 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/27 18:22:45 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i1;
	int		i2;
	char	*p;
	int		k;

	i1 = -1;
	p = (char*)haystack;
	if (!needle[0])
		return (p);
	while (haystack[++i1])
	{
		i2 = 0;
		if (needle[i2] == haystack[i1])
		{
			k = i1;
			while (haystack[i1++] == needle[i2++])
				if (!needle[i2])
					return (p);
			i1 = k;
		}
		p++;
	}
	return (0);
}
