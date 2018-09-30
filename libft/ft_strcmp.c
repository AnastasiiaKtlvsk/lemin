/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:24:01 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/03 14:18:57 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char	*s11;
	unsigned char	*s22;
	unsigned int	i;

	i = 0;
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (s11[i] && s22[i])
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	if (s11[i])
		return (s11[i]);
	if (s22[i])
		return (-s22[i]);
	return (0);
}
