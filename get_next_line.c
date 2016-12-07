/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:12:50 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/28 18:14:46 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_line	*search_and_create(int fd, t_line **begin_list)
{
	t_line *tmp;
	t_line *new;

	tmp = *begin_list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = malloc(sizeof(t_line))))
		return (NULL);
	new->stock = ft_strnew(BUFF_SIZE);
	new->fd = fd;
	new->next = *begin_list;
	*begin_list = new;
	return (new);
}

int		delete_list(t_line **begin_list, char **str)
{
	t_line *tmp;

	if (str)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	else
	{
		tmp = *begin_list;
		if (tmp->next)
			*begin_list = tmp->next;
		free(tmp);
		return (0);
	}
}

int		readbis(char **line, t_line *cur, char *tmp, char c)
{
	char	*ptr;
	int		i;

	if (tmp && c)
	{
		i = 0;
		while (tmp[i] && tmp[i] != c)
			i++;
		if (tmp[i] == c)
			return (i);
		return (0);
	}
	else
	{
		*line = ft_strsub(cur->stock, 0, readbis(NULL, NULL, cur->stock, '\n'));
		ptr = ft_strsub(cur->stock, readbis(NULL, NULL, cur->stock, '\n') + 1,
		ft_strlen(cur->stock));
		free(cur->stock);
		cur->stock = NULL;
		cur->stock = ft_strdup(ptr);
		free(ptr);
		tmp = NULL;
		return (1);
	}
}

int		end_of_file(char **line, t_line *cursor, char **buffer,
	t_line **begin_list)
{
	free(*buffer);
	*buffer = NULL;
	if (ft_strchr(cursor->stock, '\n'))
		return (readbis(line, cursor, NULL, 0));
	if (cursor->stock != NULL && ft_strlen(cursor->stock) > 0)
	{
		*line = ft_strdup(cursor->stock);
		free(cursor->stock);
		cursor->stock = NULL;
		return (1);
	}
	return (delete_list(begin_list, NULL));
}

int		get_next_line(int const fd, char **line)
{
	static t_line	*begin_list = NULL;
	t_line			*cursor;
	int				ret;
	char			*buffer;
	char			*tmp;

	if (fd < 0 || BUFF_SIZE > 1000000)
		return (-1);
	cursor = search_and_create(fd, &begin_list);
	if (ft_strchr(cursor->stock, '\n'))
		return (readbis(line, cursor, NULL, 0));
	buffer = ft_strnew(BUFF_SIZE);
	if (!(ret = read(fd, buffer, BUFF_SIZE)))
		return (end_of_file(line, cursor, &buffer, &begin_list));
	if (ret < 0)
		return (delete_list(NULL, &buffer));
	tmp = ft_strjoin(cursor->stock, buffer);
	ft_strdel(&(cursor->stock));
	cursor->stock = ft_strdup(tmp);
	delete_list(NULL, &tmp);
	delete_list(NULL, &buffer);
	return (get_next_line(fd, line));
}
