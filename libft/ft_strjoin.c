/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:09:42 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/01 17:09:45 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_join(char const *s1, char const *s2, int len)
{
	char		*s;
	int			is;
	int			i;

	if ((s = (char*)ft_memalloc(sizeof(char) * (len + 1))))
	{
		is = -1;
		i = -1;
		while (s1[++i])
			s[++is] = s1[i];
		i = -1;
		while (s2[++i])
			s[++is] = s2[i];
		s[++is] = '\0';
		return (s);
	}
	return (NULL);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int			len;
	int			i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	i = -1;
	len = 0;
	while (s1[++i])
		len++;
	i = -1;
	while (s2[++i])
		len++;
	return (ft_join(s1, s2, len));
}
