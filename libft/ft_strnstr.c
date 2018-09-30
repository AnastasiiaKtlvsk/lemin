/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:09:57 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/31 14:09:59 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack1, const char *needle1, size_t len)
{
	size_t i;

	i = (size_t)ft_strlen((char*)needle1);
	if (!(*needle1))
		return ((char*)haystack1);
	while (*haystack1 && len-- >= i)
	{
		if (*haystack1 == *needle1 && ft_memcmp(haystack1, needle1, i) == 0)
			return ((char*)haystack1);
		haystack1++;
	}
	return (NULL);
}
