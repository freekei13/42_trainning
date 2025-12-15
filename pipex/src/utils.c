#include "pipex.h"

int	open_file(char *path, int in_out)
{
	int	fd;

	if (in_out == 0)
	{
		if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
			perror(path);
		fd = open(path, O_RDONLY);
		if (fd == -1)
			fd = open("/dev/null", O_RDONLY);
		return (fd);
	}
	else if (in_out == 1)
	{
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(path);
			exit(-1);
		}
		return (fd);
	}
	return (-1);
}