#include "get_next_line.h"

char	*fill_all_line(int fd, char *buffer, char *left_line);
char	*fill_line(char *left_line);
char	*fill_left_line(char *left_line);

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*buffer;
	char		*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 0)
	{
		free(buffer);
		buffer = NULL;
		free(left_line);
		left_line = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	left_line = fill_all_line(fd, buffer, left_line);
	free(buffer);
	buffer = NULL;
	line = fill_line(left_line);
	left_line = fill_left_line(left_line);
	return (line);
}
char	*fill_all_line(int fd, char *buffer, char *left_line)
{
	char	*tmp;
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break;
		if (!left_line)
			left_line = ft_strdup("");
		buffer[bytes] = 0;
		tmp = left_line;
		left_line = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (left_line);
}

char	*fill_line(char *left_line)
{
	char	*line;

	line = ft_substr(left_line, 0, ft_line_len(left_line));
	return (line);
}

char	*fill_left_line(char *left_line)
{
	char	*tmp;

	if (left_line[0] == 0 && left_line[1] == 0)
		return (NULL);
	tmp = left_line;
	left_line = ft_substr(left_line, ft_line_len(tmp) + 1, ft_strlen(tmp) - 1);
	free(tmp);
	tmp = NULL;
	return (left_line);
}
// #include <stdio.h>

// int	main (void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *nextline = get_next_line(fd);
// 	printf("%s\n", nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s\n", nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s\n", nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s\n", nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s\n", nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s\n", nextline);
// }