#include "get_next_line.h"

static char	*fill_left_lines(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*left_lines;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (fd < 0 || BUFFER_SIZE < 0)
	{
		free(buffer);
		buffer = NULL;
		free(left_lines);
		left_lines = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	left_lines = fill_left_lines(fd, buffer);
	return (left_lines);
}

static char	*fill_left_lines(int fd, char *buffer)
{
	char	*left_lines;
	char	*tmp;

	left_lines = ft_strdup("");
	while (read(fd, buffer, BUFFER_SIZE))
	{
		tmp = ft_strdup(buffer);
		left_lines = ft_strjoin(left_lines, tmp);
	}
	return (left_lines);
}

#include <stdio.h>

int	main (void)
{
	int fd = open("text.txt", O_RDONLY);
	char *nextline = get_next_line(fd);
	printf("%s\n", nextline);
}