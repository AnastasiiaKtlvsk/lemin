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

int     main(void)
{
    t_l tl;

    write(1, "start\n", 6);
    
    if (read_data(&tl))
        process(&tl);

    return (0);
}