#include "get_next_line.h"

size_t	get_index_newline(char *data)
{
	size_t	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		data[1024];
	static char	*storage;
	int	endline;
	char	*line;
	ssize_t	size;

	if (!storage)
		storage = ft_strdup("");
	while (size > 0)
	{
		size = read(fd, data, BUFFER_SIZE);
		storage = ft_strjoin(storage, data);
		data[size] = '\0';
		endline = get_index_newline(storage);
		if (endline != -1)
		{
			line = ft_substr(storage, 0, endline);
			break;
		}
	}
	storage = ft_strdup(storage + endline + 1);
	return (line);
}