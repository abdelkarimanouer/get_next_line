/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:23:06 by aanouer           #+#    #+#             */
/*   Updated: 2025/11/05 10:03:52 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmpc;

	if (!s)
		return (NULL);
	i = 0;
	tmpc = (char)c;
	while (s[i])
	{
		if (s[i] == tmpc)
			return ((char *)&s[i]);
		i++;
	}
	if (tmpc == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

static char	*return_line(char **container)
{
	char	*line;
	char	*tmp;
	size_t	i;

	if (*container == NULL || (*container)[0] == '\0')
		return (NULL);
	i = 0;
	while ((*container)[i] != '\0' && (*container)[i] != '\n')
		i++;
	line = ft_substr(*container, 0, i + ((*container)[i] == '\n'));
	tmp = *container;
	*container = ft_strdup(*container + i + ((*container)[i] == '\n'));
	free(tmp);
	if (!line || !*container)
		return (free(line), NULL);
	return (line);
}

static char	*read_data(int fd, char **container)
{
	char	*data_read;
	char	*tmp;
	ssize_t	bytes_read;

	data_read = malloc((size_t)BUFFER_SIZE + 1);
	if (!data_read)
		return (free(*container), *container = NULL, NULL);
	while (!ft_strchr(*container, '\n'))
	{
		bytes_read = read(fd, data_read, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(data_read), free(*container), *container = NULL, NULL);
		if (bytes_read == 0)
			break ;
		data_read[bytes_read] = '\0';
		tmp = *container;
		*container = ft_strjoin(*container, data_read);
		free(tmp);
		if (!*container)
			return (free(data_read), NULL);
	}
	return (free(data_read), *container);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!container)
		container = ft_strdup("");
	if (!container || !read_data(fd, &container))
		return (free(container), container = NULL, NULL);
	line = return_line(&container);
	if (!line)
		return (free(container), container = NULL, NULL);
	return (line);
}
