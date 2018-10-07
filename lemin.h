/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:23:08 by akotilie          #+#    #+#             */
/*   Updated: 2018/09/22 21:32:36 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>

# include "stdio.h"


typedef	struct		s_r
{
    char			*n; // name of room
    int				x;
    int				y;
    int				iS; //isStart
    int				iE;	//isEnd
    int				f; //isBooked (number of ants at the start and at the end and name of ant in usuall rooms)
    struct s_r      *nx; // next
    char    		*rl;
    int             st; // number of step
}					t_r;

typedef	struct		s_l
{
    int				na; //number of ants
    char			*c; //comments
    char			*rl; //relations (not parsed)
    t_r				*r; //rooms
    int             sn; //number of starts
    int             en; // number of ends
    char            *res; // result (L1-room1)
}					t_l;

int					read_data(t_l *tl);
t_r                 *ret_end(t_l *tl);
int      process(t_l *tl);
t_r      *find_r_by_n(t_l *tl, char *n);

#endif
