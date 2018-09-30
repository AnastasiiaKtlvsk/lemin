/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:13:18 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/01 16:13:20 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*k;
	int			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if ((k = (char*)ft_memalloc(sizeof(char) * (i + 1))))
	{
		i = -1;
		while (s[++i])
			k[i] = f(i, (char)s[i]);
		k[i] = '\0';
		return (k);
	}
	return (NULL);
}
