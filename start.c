/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:12:33 by akotilie          #+#    #+#             */
/*   Updated: 2018/09/30 17:12:35 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char**argv)
{
	t_l tl;
	char *temp;

	tl.res = NULL;
	tl.sn = 0;
	tl.en = 0;
	tl.nl = NULL;
	tl.r = NULL;
	tl.st = NULL;
	tl.ed = NULL;
	if (read_na(&tl, temp, 0) && read_data(&tl, temp, 1) &&
		relations(&tl, -1) && tl.sn != 1 && tl.en != 1)
		process(&tl);
	else
		ft_putstr("Error\n");
    system("leaks lem-in");
	return (0);
}
