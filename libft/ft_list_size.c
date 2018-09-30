/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 19:19:49 by akotilie          #+#    #+#             */
/*   Updated: 2017/08/08 19:19:51 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = begin_list;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
