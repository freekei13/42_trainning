#include "parser.h"

int	dir_color_init(t_data *data, char *map_info)
{
	if (ft_strnstr(map_info, "NO ", 3) != NULL
		|| ft_strnstr(map_info, "SO ", 3) != NULL
		|| ft_strnstr(map_info, "WE ", 3) != NULL
		|| ft_strnstr(map_info, "EA ", 3) != NULL)
	{
		if (dir_init(data, map_info) != 0)
			return (1);
	}
	else if (ft_strnstr(map_info, "F ", 2) != NULL
		|| ft_strnstr(map_info, "C ", 2) != NULL)
	{
		if (floor_ceil_init(data, map_info) != 0)
			return (1);
	}
	return (0);
}
