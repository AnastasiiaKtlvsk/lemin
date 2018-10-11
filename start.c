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

# include "lemin.h"

int     main(int argc, char**argv)
{
    t_l tl;
    char *temp;

    tl.sn = 0;
    tl.en = 0;
    if (read_data(&tl, temp))
        process(&tl);
    else
        ft_putstr("Error\n");
    free_lm(&tl);
    return (0);
}