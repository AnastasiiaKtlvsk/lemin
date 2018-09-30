/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:37:24 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/06 14:37:26 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if ((newlist = ft_memalloc(sizeof(t_list))))
	{
		if ((newlist->content = ft_memalloc(content_size)))
		{
			if (!content)
			{
				newlist->content = NULL;
				newlist->content_size = 0;
			}
			else
			{
				ft_memcpy(newlist->content, content, content_size);
				newlist->content_size = content_size;
			}
			newlist->next = (t_list*)NULL;
			return (newlist);
		}
	}
	return ((t_list*)NULL);
}
