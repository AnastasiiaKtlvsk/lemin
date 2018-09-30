/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:46:23 by akotilie          #+#    #+#             */
/*   Updated: 2017/10/27 16:46:25 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int		count;

	count = 0;
	str = NULL;
	while (src[count])
		count++;
	if ((str = (((char *)malloc(sizeof(char) * count + 1)))))
	{
		count = -1;
		while (src[++count])
			str[count] = src[count];
		str[count] = '\0';
	}
	return (str);
}
