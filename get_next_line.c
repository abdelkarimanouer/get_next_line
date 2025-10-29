/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:23:06 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/29 13:52:23 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	get_index_newline(char *data)
{
	ssize_t	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*free_storage(ssize_t size, char **storage, char *line)
{
	if (size < 0)
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	if (*storage && (*storage)[0] != '\0')
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return (line);
	}
	return (NULL);
}

static char	*return_line(char *line, char **storage, char *tmp, ssize_t endline)
{
	line = ft_substr(*storage, 0, endline + 1);
	tmp = *storage;
	*storage = ft_strdup(*storage + endline + 1);
	free(tmp);
	return (line);
}

static char	*get_line(char **storage, char *line, int fd, char *data)
{
	ssize_t	endline;
	ssize_t	size;
	char	*tmp;

	if (!*storage)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, data, BUFFER_SIZE);
		if (size < 0)
			free_storage(size, storage, line);
		data[size] = '\0';
		tmp = *storage;
		*storage = ft_strjoin(*storage, data);
		free(tmp);
		endline = get_index_newline(*storage);
		if (endline != -1)
			return (return_line(line, storage, tmp, endline));
		if (size == 0)
			break ;
	}
	return (free_storage(size, storage, line));
}

char	*get_next_line(int fd)
{
	char		data[1024];
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!storage)
		storage = ft_strdup("");
	line = get_line(&storage, line, fd, data);
	if (!line && storage)
	{
		free(storage);
		storage = NULL;
	}
	return (line);
}
