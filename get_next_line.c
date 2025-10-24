// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include "get_next_line.h"

// # define BUFFER_SIZE 40

// int	main(void)
// {
// 	static char	data[1024];
// 	int fd = open("file.txt", O_RDONLY);
// 	size_t	size = read(fd, data, BUFFER_SIZE);
// 	char	*tmp = ft_strjoin(data, "");
// 	size = read(fd, data, BUFFER_SIZE);
// 	tmp = ft_strjoin(tmp, data);
// 	size = read(fd, data, BUFFER_SIZE);
// 	tmp = ft_strjoin(tmp, data);
// 	size = read(fd, data, BUFFER_SIZE);
// 	tmp = ft_strjoin(tmp, data);
// 	size = read(fd, data, size);
// 	tmp = ft_strjoin(tmp, data);
// 	size = read(fd, data, size);
// 	tmp = ft_strjoin(tmp, data);
// 	size = read(fd, data, size);
// 	tmp = ft_strjoin(tmp, data);
// 	size = read(fd, data, size);
// 	tmp = ft_strjoin(tmp, data);
// 	size = read(fd, data, size);
// 	tmp = ft_strjoin(tmp, data);
// 	printf("%s\n", tmp);

// 	free(tmp);

// 	return (0);
// }
