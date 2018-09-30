/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:07:24 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/24 15:07:27 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int sqrt;
	int s;
	int r;

	s = 1;
	r = nb;
	sqrt = 0;
	while (r - s >= 0)
	{
		r = r - s;
		s = s + 2;
		sqrt = sqrt + 1;
	}
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (0);
}
