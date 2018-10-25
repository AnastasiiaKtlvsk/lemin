/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:12:48 by akotilie          #+#    #+#             */
/*   Updated: 2018/09/30 17:12:50 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_l tl;
	char *temp;

	if (read_data(&tl, temp, 1)) {
		process(&tl);
	}
	else
		ft_putstr("Error\n");
	free_lm(&tl);
	return (0);
}
