#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef TILE_SIZE
#  define TILE_SIZE 16
# endif
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_map
{
	int	width;
	int	height;
}		t_map;

typedef	struct s_pos
{
	int	x;
	int	y;
}		t_pos;


typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		**map;
	t_map		size;
	t_pos		p_pos;
	void		*c_img;
	void		*e_img;
	void		*p_img;
	void		*f_img;
	void		*w_img;
	int			move_count;
	int			collec_count;
}				t_data;

void	free_all(char **strs);
void	free_all_img(t_data *data);
int		ft_tablen(char **strs);
int		exit_game(t_data *data);

int		element_to_count(char **map, char element);
char	**map_parse(int fd);
char	**map_check(char *file_path);

t_data	set_data(char **map);
void	*set_img(void *mlx, char *path);
void	map_render(t_data *data);

int		key_actions(int key, t_data *data);
#endif