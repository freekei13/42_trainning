#include "so_long.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 2 || argc < 2)
		return (0);
	if (map_check(argv[1]) == 0)
		return (0);
	boot_game(argv[1]);
}