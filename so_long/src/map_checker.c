#include "so_long.h"

int	ismap_rectang(char **map)
{
	int	width;
	int	i;

	width = ft_strlen(map[0]);
	i = 1;
	while(map[i])
	{
		if (width != (int)ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (ft_printf("Map is rectangular\n"), 1);
}

int	ismap_wallaround(char **map)
{
	int	i;
	int	j;
	t_map	map_d;

	map_d.height = ft_tablen(map);
	map_d.width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == map_d.height - 1)
		{
			while (j < map_d.width - 2)
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
			if (map[i][0] != '1' || map[i][map_d.width - 2] != '1')
				return (0);
		i++;
	}
	return (ft_printf("Wall are arounded\n"), 1);
}

int	element_to_count(char **map, char element)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

char	**map_check(char *file_path)
{
	int		fd;
	char	**map;

	fd = open(file_path, O_RDONLY);
	if (!fd)
		return (0);
	map = map_parse(fd);
	if (!map)
		return (0);
	if (ismap_rectang(map) == 0)
		return (free_all(map), ft_printf("Error: map is not rectangular\n"), NULL);
	if (ismap_wallaround(map) == 0)
		return (free_all(map), ft_printf("Error: No wall arounded\n"), NULL);
	if (element_to_count(map, 'E') != 1)
		return (free_all(map), ft_printf("Error: 0 or more than 1 Exit\n"), NULL);
	if (element_to_count(map, 'P') != 1)
		return (free_all(map), ft_printf("Error: 0 or more than 1 Start position\n"), NULL);
	if (element_to_count(map, 'C') == 0)
		return (free_all(map), ft_printf("Error: 0 Collectible\n"), NULL);
	return (ft_printf("--All check passed!--\n"), map);
}
