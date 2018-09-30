/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:29:31 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 12:46:19 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && i < (int)n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (((s1[i] && !s2[i]) || (!s1[i] && s2[i])) && i < (int)n)
			return (0);
	}
	return (1);
}
