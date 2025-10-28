#include "get_next_line.h"

static ssize_t get_index_newline(char *data)
{
	ssize_t i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char *free_storage(char *storage, char *line)
{
	if (storage && storage[0] != '\0')
	{
		line = ft_strdup(storage);
		free(storage);
		storage = NULL;
		return (line);
	}
	return (NULL);
}

static char	*get_line(char *storage, char *line, int fd, char *data)
{
	ssize_t	endline;
	ssize_t	size;
	char	*tmp;

	size = 1;
	while (size > 0)
	{
		size = read(fd, data, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		data[size] = '\0';
		tmp = storage;
		storage = ft_strjoin(storage, data);
		free(tmp);
		endline = get_index_newline(storage);
		if (endline != -1)
		{
			line = ft_substr(storage, 0, endline);
			storage = ft_strdup(storage + endline + 1);
			return (line);
		}
		if (size == 0)
			break;
	}
	return (free_storage(storage, line));
}

char *get_next_line(int fd)
{
	char data[1024];
	char *line;
	static char *storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!storage)
		storage = ft_strdup("");
	return get_line(storage, line, fd, data);
}
