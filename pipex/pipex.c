#include "pipex.h"

int	main(int argc, char **argv)
{
	int	fd_in;
	int	fd_out;

	if (argc < 5 || argc > 5)
		return (0);

	fd_in = open("infile", O_RDONLY);
	fd_out = open("outfile", O_WRONLY);
}