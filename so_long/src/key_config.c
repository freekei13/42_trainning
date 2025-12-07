#include "so_long.h"
#include "/usr/include/X11/keysym.h"

int	key_actions(int key, t_data *data)
{
	if (key == XK_Escape)
		exit_game(data);
	if (key == 'w')
	{
		data->map[data->p_pos.y][data->p_pos.x] = '0';
		data->map[data->p_pos.y - 1][data->p_pos.x] = 'P';
		data->p_pos.y -= 1;
		mlx_clear_window(data->mlx, data->window);
		map_render(*data);
	}
	return (0);
}
