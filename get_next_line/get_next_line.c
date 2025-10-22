#include "get_next_line.h"

char	*fill_line_left_line(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*left_lines;
	char	*buffer;
	char	*line;

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
	line = fill_line_left_line(fd, buffer);
	return (line);
}

char	*fill_line_left_line(int fd, char *buffer)
{
	char	*line;

	read(fd, buffer, BUFFER_SIZE);
	line = ft_strdup(buffer);
	free(buffer);
	return (line);
}
#include <stdio.h>

int	main (void)
{
	printf("%s\n", get_next_line(open("text.txt", O_RDONLY)));
}