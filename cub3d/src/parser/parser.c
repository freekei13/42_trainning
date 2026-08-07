#include "parser.h"

int    map_data_init(t_data *data, char **map_info)
{
	int     i;
	int     map_counter;

	data->map.map = NULL;
	map_counter = 0;
	i = 0;
	while (map_info[i])
	{
		if (dir_color_init(data, map_info[i]) != 0)
			return (1);
		if (map_info[i][0] != '\n' && map_info[i][0] != 'N'
				&& map_info[i][0] != 'S' && map_info[i][0] != 'W'
				&& map_info[i][0] != 'E' && map_info[i][0] != 'F'
				&& map_info[i][0] != 'C')
		{
			data->map.map = realloc(data->map.map, sizeof(char *) * (2 + map_counter));
			if (!data->map.map)
				return (1);
			data->map.map[map_counter] = ft_strdup(map_info[i]);
			data->map.map[map_counter + 1] = NULL;
			map_counter++;
		}
		i++;
	}
	return (0);
}
