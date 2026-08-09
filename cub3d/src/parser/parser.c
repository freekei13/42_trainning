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

void	t_player_init(t_player *player, int x, int y, char dir)
{
	if (dir == 'N' || dir == 'S' || dir == 'W' || dir == 'E')
	{
		player->player_nb += 1;
		//Le +0.5 évite que le joueur démarre collé à un 
		//mur ou pile sur une frontière de case (ce qui peut 
		//casser tes calculs de collision dès le premier frame).
		player->pos_x = (double)x + 0.5;
		player->pos_y = (double)y + 0.5;
		if (dir == 'N')
		{
			player->dir_x = 0;
			player->dir_y = -1;
			player->plane_x = 0.66;
			player->plane_y = 0;
		}
	}
	(void)player;
}

int	player_position(t_data *data)
{
	int	i;
	int	j;

	if (!data->map.map)
		return (1);
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{	
			if (data->player.player_nb > 1)
				return (1);
			t_player_init(&data->player, j, i, data->map.map[i][j]);
			j++;			
		}
		i++;
	}
	return (0);
}

int	player_data_init(t_data *data)
{
	data->player.player_nb = 0;
	if (player_position(data) == 1)
		return (1);
	return (0);
}
