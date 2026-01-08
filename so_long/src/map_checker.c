/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:20:12 by csamakka          #+#    #+#             */
/*   Updated: 2026/01/08 10:44:35 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ismap_rectang(char **map)
{
	int	width;
	int	i;

	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (width != (int)ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (ft_printf("Map is rectangular\n"), 1);
}

int	ismap_wallaround(char **map)
{
	int		i;
	int		j;
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
		while (map[i][j])
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	file_path_check(char *file_path)
{
	int		len;
	int		i;
	char	*filename;

	len = ft_strlen(file_path);
	filename = ft_substr(file_path, len - 4, 4);
	if (ft_strncmp(filename, ".ber", 4) != 0)
		return (0);
	return (1);
}

char	**map_check(char *file_path)
{
	int		fd;
	char	**map;

	if (file_path_check(file_path) == 0)
		return (0);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	map = map_parse(fd);
	if (!map)
		return (0);
	if (ismap_rectang(map) == 0)
		return (free_all(map), ft_printf("Error: Not rectangular\n"), NULL);
	if (ismap_wallaround(map) == 0)
		return (free_all(map), ft_printf("Error: Wall\n"), NULL);
	if (element_to_count(map, 'E') != 1)
		return (free_all(map), ft_printf("Error: Exit\n"), NULL);
	if (element_to_count(map, 'P') != 1)
		return (free_all(map), ft_printf("Error: Start position\n"), NULL);
	if (element_to_count(map, 'C') == 0)
		return (free_all(map), ft_printf("Error: Collectible\n"), NULL);
	if (isacces(map) == 0)
		return (free_all(map), ft_printf("Error: No access\n"), NULL);
	return (ft_printf("--All check passed!--\n"), map);
}
