#include "get_next_line.h"

static char	*fill_left_line(int fd, char *buffer);
static char *fill_line(char *left_line, char *line);

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*buffer;
	char		*line;

	line = ft_strdup("");
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
	left_line = fill_left_line(fd, buffer);
	line = fill_line(left_line, line);
	return (line);
}

static char	*fill_left_line(int fd, char *buffer)
{
	char	*left_line;
	char	*tmp;

	left_line = ft_strdup("");
	read(fd, buffer, BUFFER_SIZE);
	tmp = ft_strdup(buffer);
	left_line = ft_strjoin(left_line, tmp);
	free(buffer);
	free(tmp);
	return (left_line);
}

char *fill_line(char *left_line, char *line)
{
	line = ft_substr(left_line, 0, ft_line_len(left_line));
	return (line);
}
#include <stdio.h>

int	main (void)
{
	int fd = open("text.txt", O_RDONLY);
	char *nextline = get_next_line(fd);
	printf("%s\n", nextline);
}