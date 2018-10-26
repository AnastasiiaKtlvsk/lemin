/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 22:51:56 by akotilie          #+#    #+#             */
/*   Updated: 2018/10/26 22:51:58 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_res(t_l *tl)
{
	tl->pr = ft_strcat(tl->pr, "\n");
	ft_putstr(tl->pr);
	if (tl->c && ft_strlen(tl->c))
	{
		ft_putstr("Comments: \n");
		ft_putstr(tl->c);
		ft_putstr("\n");
	}
	ft_putstr(tl->res);
}
