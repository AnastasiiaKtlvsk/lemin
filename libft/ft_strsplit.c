/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:19:14 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/14 17:00:26 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countw(char const *s, char c)
{
	int			count;
	int			i;

	count = -1;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count + 1);
}

static int		ft_countl(const char *s, char c, int k)
{
	int			count;

	count = 0;
	while (s[k] != c && s[k])
	{
		k++;
		count++;
	}
	return (count);
}

static char		**ft_nullsplit(void)
{
	char		**arr;

	if ((arr = (char **)ft_memalloc(1)))
	{
		arr[0] = NULL;
		return (arr);
	}
	return (NULL);
}

static char		**ft_split(char const *s, char c, char **arr)
{
	int			i;
	int			j;
	int			k;

	k = 0;
	i = 0;
	j = 0;
	while (j < ft_countw(s, c))
	{
		while (s[k] == c && s[k])
			k++;
		if ((arr[j] = (char *)ft_memalloc(sizeof(char) * ft_countl(s, c, k))))
		{
			i = 0;
			while (s[k] != c && s[k])
				arr[j][i++] = s[k++];
			arr[j][i] = '\0';
		}
		j++;
	}
	arr[j] = 0;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	const char	*s2;
	char		**arr;

	s2 = s;
	if (s2)
	{
		if ((arr = (char **)ft_memalloc(sizeof(char*) * (ft_countw(s, c) + 1))))
			return (ft_split(s, c, arr));
	}
	return (ft_nullsplit());
}
