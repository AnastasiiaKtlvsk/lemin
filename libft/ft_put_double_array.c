/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_double_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:57:55 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/16 14:57:57 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_double_array(char **arr)
{
	int i;
	int j;

	j = -1;
	while (arr[++j])
	{
		i = -1;
		while (arr[j][++i])
			ft_putchar(arr[j][i]);
	}
}
