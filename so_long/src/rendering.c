#include "so_long.h"

void	background_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			mlx_put_image_to_window(data->mlx, data->window, data->f_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	elements_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->w_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->e_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->c_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	player_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->p_img.p_down, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	player_render_key(t_data *data, int key)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && key == 's')
				mlx_put_image_to_window(data->mlx, data->window, data->p_img.p_down, j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == 'P' && key == 'w')
				mlx_put_image_to_window(data->mlx, data->window, data->p_img.p_up, j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == 'P' && key == 'a')
				mlx_put_image_to_window(data->mlx, data->window, data->p_img.p_left, j * TILE_SIZE, i * TILE_SIZE);
			if (data->map[i][j] == 'P' && key == 'd')
				mlx_put_image_to_window(data->mlx, data->window, data->p_img.p_right, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	map_render(t_data *data)
{
	background_render(data);
	elements_render(data);
	player_render(data);
}
