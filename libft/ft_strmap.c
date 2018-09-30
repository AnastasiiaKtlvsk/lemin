/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:58:31 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/01 15:58:34 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*k;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if ((k = (char*)ft_memalloc(sizeof(char) * (i + 1))))
	{
		i = -1;
		while (s[++i])
			k[i] = f((char)s[i]);
		k[i] = '\0';
		return (k);
	}
	return (NULL);
}
