/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:09:12 by kskostyl          #+#    #+#             */
/*   Updated: 2019/03/08 20:04:52 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int				res(int fd, char **text, char **line)
{
	int			len;
	char		*tmp;

	len = 0;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	if (text[fd][len] == '\n')
	{
		*line = ft_strsub(text[fd], 0, len);
		tmp = ft_strdup(&text[fd][len + 1]);
		ft_strdel(&text[fd]);
		text[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(text[fd]);
		ft_strdel(&text[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*text[FD_MAX];
	int			num;

	if (fd < 0 || !line || (read(fd, buf, 0) < 0) ||
			fd > FD_MAX || BUFF_SIZE <= 0)
		return (-1);
	if (!text[fd])
		text[fd] = ft_strnew(1);
	while ((num = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[num] = '\0';
		tmp = ft_strjoin(text[fd], buf);
		ft_strdel(&text[fd]);
		text[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (text[fd][0] == '\0')
		return (0);
	return (res(fd, text, line));
}
