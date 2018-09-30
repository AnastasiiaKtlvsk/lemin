/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:29:04 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 14:29:06 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *cur;

	if (lst && f)
	{
		cur = lst;
		while (cur->next)
		{
			f(cur);
			cur = cur->next;
		}
		f(cur);
	}
}
