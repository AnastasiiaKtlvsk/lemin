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

typedef	struct		s_l
{
	int				*n; // number of ants
	char			*s; //start
	char			*e; // end
	char			**r; //relations
	char			*c; //comment
}					t_l;

int					read_data(t_l *tl);

#endif
