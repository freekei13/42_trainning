#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc(5);
	read(fd, buffer, 5);
	return (buffer);
}
#include <stdio.h>

int	main (void)
{
	printf("%s\n", get_next_line(open("text.txt", O_RDONLY)));
}