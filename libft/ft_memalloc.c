/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_memalloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:01:39 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/31 19:01:42 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *set;

	if ((set = (void *)malloc(size)))
	{
		ft_bzero(set, size);
		return (set);
	}
	else
		return (NULL);
}
