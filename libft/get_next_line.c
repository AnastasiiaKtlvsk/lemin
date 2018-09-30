/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:25:23 by akotilie          #+#    #+#             */
/*   Updated: 2018/08/18 13:25:29 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			check_for_newline(char **str, char **line)
{
	int		len;
	char	*newline;
	char	*temp;

	if (!(*str))
		return (0);
	newline = ft_strchr(*str, 10);
	if (newline)
	{
		len = newline - *str;
		temp = *str;
		*line = ft_strsub(temp, 0, len);
		*str = ft_strsub(temp, len + 1, ft_strlen(temp) - len - 1);
		free(temp);
		return (1);
	}
	return (0);
}

static int	read_zsh(char **str, int fd, char **line)
{
	int		ret;
	char	*buf;
	char	*temp;

	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = *str;
		*str = ft_strjoin(temp, buf);
		free(temp);
		ft_strclr(buf);
		if (check_for_newline(str, line))
		{
			ft_strdel(&buf);
			return (1);
		}
	}
	ft_strdel(&buf);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char *massiv[4096];

	if (read(fd, 0, 0) < 0)
		return (-1);
	if (!massiv[fd])
		massiv[fd] = ft_strnew(0);
	if (check_for_newline(&massiv[fd], line))
		return (1);
	if (read_zsh(&massiv[fd], fd, line))
		return (1);
	if (massiv[fd] == NULL || !massiv[fd][0])
		return (0);
	*line = ft_strdup(massiv[fd]);
	ft_strdel(&massiv[fd]);
	return (1);
}
