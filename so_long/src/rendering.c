#include "so_long.h"

void	background_render(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j] && data.map[i][j] != '\n')
		{
			mlx_put_image_to_window(data.mlx, data.window, data.f_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	elements_render(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '1')
				mlx_put_image_to_window(data.mlx, data.window, data.w_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data.map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx, data.window, data.e_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data.map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx, data.window, data.c_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	map_render(t_data data)
{
	int	i;
	int	j;

	background_render(data);
	elements_render(data);
	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			
			if (data.map[i][j] == 'P')
				mlx_put_image_to_window(data.mlx, data.window, data.p_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
