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

int flood_fill(char **map, int p_x, int p_y)
{
	int	height;
	int	widgth;
	int i;

	if (!map[p_x])
		return (0);
	i = 0;
	while (map[i])
		i++;
	height = i;
	widgth = ft_strlen(map[p_x]) - 1;
	if (p_x < 0 || p_x >= height || p_y < 0 || p_y >= widgth)
		return (0);
	else if (map[p_x][p_y] == '1' || map[p_x][p_y] == 'F')
	{
		if (map[p_x][p_y] == 'F' && (!map[p_x + 1] || !map[p_x][p_y + 1]
			|| !map[p_x - 1] || !map[p_x][p_y - 1] || map[p_x + 1][p_y] == ' '
			|| map[p_x][p_y + 1] == ' ' || map[p_x - 1][p_y] == ' '
			|| map[p_x][p_y - 1] == ' '))
			return (1);
		return (0);
	}
	if (!map[p_x + 1] || !map[p_x][p_y + 1] || !map[p_x - 1]
		|| !map[p_x][p_y - 1] || map[p_x + 1][p_y] == ' '
		|| map[p_x][p_y + 1] == ' ' || map[p_x - 1][p_y] == ' '
		|| map[p_x][p_y - 1] == ' ')
		return (1);
	map[p_x][p_y] = 'F';
	if (flood_fill(map, p_x + 1, p_y) == 1)
		return (1);
	if (flood_fill(map, p_x - 1, p_y) == 1)
		return (1);
	if (flood_fill(map, p_x, p_y + 1) == 1)
		return (1);
	if (flood_fill(map, p_x, p_y - 1) == 1)
		return (1);
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	return (0);
}
