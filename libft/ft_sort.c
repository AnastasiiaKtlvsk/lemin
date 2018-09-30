/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:32:41 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/16 18:32:43 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(char **params, int count)
{
	char	*temp;
	int		i;
	int		j;
	int		k;

	k = 0;
	while (++k < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			i = 0;
			while (params[j][i] == params[j + 1][i])
				i++;
			if (params[j][i] > params[j + 1][i])
			{
				temp = params[j];
				params[j] = params[j + 1];
				params[j + 1] = temp;
			}
		}
	}
}
