#include "get_next_line.h"

char		*fill_line(int fd, char *buffer);
static char *fill_left_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*buffer;
	char		*line;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
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
	line = fill_line(fd, buffer);
	left_line = fill_left_line(buffer);
	free(buffer);
	buffer = NULL;
	return (line);
}

char	*fill_line(int fd, char *buffer)
{
	char	*line;

	read(fd, buffer, BUFFER_SIZE);
	line = ft_substr(buffer, 0, ft_line_len(buffer) - 1);
	return (line);
}

static char *fill_left_line(char *buffer, char *left_line)
{
	char	*tmp;

	tmp = ft_strdup(left_line);
	left_line = ft_strjoin(tmp, buffer);
	return (left_line);
}
#include <stdio.h>

int	main (void)
{
	int fd = open("text.txt", O_RDONLY);
	char *nextline = get_next_line(fd);
	printf("%s\n", nextline);
	nextline = get_next_line(fd);
	printf("%s\n", nextline);
	free(nextline);
	nextline = NULL;
}