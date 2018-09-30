/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:31:20 by akotilie          #+#    #+#             */
/*   Updated: 2017/11/12 12:39:12 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_space(int n)
{
	int space;
	int p;

	space = 2;
	p = n;
	if (p < 0)
	{
		space++;
		p = -p;
	}
	while (p / 10 > 0)
	{
		space++;
		p = p / 10;
	}
	return (space);
}

static char		*ft_reverse(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(s) - 1;
	if (s[0] == '-')
		i++;
	while (i < j)
	{
		temp = s[i];
		s[i++] = s[j];
		s[j--] = temp;
	}
	return (s);
}

static char		*ft_intmin(char *s)
{
	char	*s1;
	int		i;
	int		k;

	s1 = (char*)ft_memalloc(sizeof(char) * 11);
	s = ft_itoa(-214748);
	s1 = ft_itoa(3648);
	i = 0;
	k = 0;
	while (s[i])
		i++;
	while (s1[k])
		s[i++] = s1[k++];
	s[i] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = -1;
	if ((s = ft_memalloc(ft_space(n))))
	{
		if (n == -2147483648)
			return (ft_intmin(s));
		if (n < 0)
		{
			s[++i] = '-';
			n = -n;
		}
		while (n > 9)
		{
			s[++i] = n % 10 + '0';
			n = n / 10;
		}
		s[++i] = n + '0';
		s[++i] = '\0';
		return (ft_reverse(s));
	}
	return (NULL);
}
