#include "so_long.h"

void	*set_img(void *mlx, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	return (img);
}

void	boot_game(char *file_path)
{
	t_data	data;
	int		fd;
	int		i;
	int		j;

	fd = open(file_path, O_RDONLY);
	i = 0;
	data.mlx = mlx_init();
	data.c_img = set_img(data.mlx, "./sprite/collectible.xpm");
	data.e_img = set_img(data.mlx, "./sprite/exit.xpm");
	data.p_img = set_img(data.mlx, "./sprite/character_down.xpm");
	data.f_img = set_img(data.mlx, "./sprite/floor.xpm");
	data.w_img = set_img(data.mlx, "./sprite/wall.xpm");
	data.map = map_parse(fd);
	data.size.height = ft_tablen(data.map);
	data.size.width = ft_strlen(data.map[0]) - 1;
	data.window = mlx_new_window(data.mlx, data.size.width * TILE_SIZE, data.size.height * TILE_SIZE, "so_long");
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '1')
				mlx_put_image_to_window(data.mlx, data.window, data.w_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data.map[i][j] == '0')
				mlx_put_image_to_window(data.mlx, data.window, data.f_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data.map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx, data.window, data.e_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data.map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx, data.window, data.c_img, j * TILE_SIZE, i * TILE_SIZE);
			if (data.map[i][j] == 'P')
				mlx_put_image_to_window(data.mlx, data.window, data.p_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	mlx_loop(data.mlx);
}