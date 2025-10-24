#include "get_next_line.h"

char	*fill_all_line(int fd, char *buffer, char *left_line);
char	*fill_left_line(char *line);

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
	line = fill_all_line(fd, buffer, left_line);
	free(buffer);
	buffer = NULL;
	left_line = fill_left_line(line);
	return (line);
}

char	*fill_all_line(int fd, char *buffer, char *left_line)
{
	char	*tmp;
	ssize_t bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(left_line);
			return (NULL);
		}
		else if (bytes == 0)
			break;
		buffer[bytes] = 0;
		if (!left_line)
			left_line = ft_strdup("");
		tmp = left_line;
		left_line = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(left_line, '\n'))
			break;
	}
	return (left_line);
}

char	*fill_left_line(char *line)
{
	char	*left_line;
	
	left_line = ft_substr(line, ft_line_len(line) + 1, ft_strlen(line) - 1);
	if (*left_line == 0)
	{
		free(left_line);
		left_line = NULL;
	}
	line[ft_line_len(line) + 1] = 0;
	return (left_line);
}

#include <stdio.h>

int	main (void)
{
	int fd = open("text.txt", O_RDONLY);
	char *nextline = get_next_line(fd);
	while (nextline != NULL)
	{
		printf("%s", nextline);
		nextline = get_next_line(fd);
	}
}