/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:33:03 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 14:33:05 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	if (!(cur = f(lst)))
		return (NULL);
	new_lst = cur;
	while (lst->next)
	{
		lst = lst->next;
		if (!(cur->next = f(lst)))
			return (NULL);
		cur = cur->next;
	}
	return (new_lst);
}
