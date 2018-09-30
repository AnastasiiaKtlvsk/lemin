/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:57:28 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/01 17:57:34 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(char const *s)
{
	int length;
	int i;

	i = 0;
	length = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i])
	{
		i++;
		length++;
	}
	while (s[--i] == ' ' || s[i] == '\t' || s[i] == '\n')
		--length;
	if (length < 2)
		return (1);
	return (length);
}

char			*ft_strtrim(char const *s)
{
	int		is;
	char	*c;
	int		ic;
	int		length;

	if (s)
	{
		is = 0;
		ic = 0;
		length = ft_length(s);
		if ((c = ft_memalloc(length)))
		{
			while (s[is] == ' ' || s[is] == '\t' || s[is] == '\n')
				is++;
			while (length-- > 1)
				c[ic++] = s[is++];
			c[ic] = '\0';
			return (c);
		}
	}
	return (NULL);
}
