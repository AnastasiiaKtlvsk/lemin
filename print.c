/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:12:33 by akotilie          #+#    #+#             */
/*   Updated: 2018/09/30 17:12:35 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_res(t_l *tl)
{
	tl->pr = ft_strcat(tl->pr,"\n");
	//ft_putstr(tl->pr);
	if (tl->c && ft_strlen(tl->c))
	{
		ft_putstr("Comments: \n");
		ft_putstr(tl->c);
		ft_putstr("\n");
	}
	ft_putstr(tl->res);
}
