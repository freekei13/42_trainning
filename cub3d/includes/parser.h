#ifndef PARSER_H
# define PARSER_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_player
{
    //double (pas int — le joueur doit pouvoir être à une position fractionnaire dans une case,
    //indispensable pour le mouvement fluide et le raycasting)
    double  pos_x;
    double  pos_y;
    //dir (dirX, dirY) : le vecteur qui pointe dans la direction où regarde le joueur.
    //plane (planeX, planeY) : le "plan de caméra", perpendiculaire à dir, qui définit
    //le champ de vision (FOV). C'est ce vecteur qui te permettra plus tard de balayer
    //tous les rayons de l'écran gauche à droite

    //vecteur direction
    double  dir_x;
    double  dir_y;
    //vecteur plan camera
    double  plane_x;
    double  plane_y;
    int     player_nb;
}           t_player;

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
    char    *texture_no;
    char    *texture_so;
    char    *texture_we;
    char    *texture_ea;
    int     color_f;
    int     color_c;
}           t_map;

typedef struct s_data
{
    void        *mlx;
    void        *mlx_win;
    t_player    player;
    t_map       map;
}               t_data;

char    **map_info_parser(char *map_path);
int	    dir_color_init(t_data *data, char *map_info);
int     map_data_init(t_data *data, char **map_info);
int     dir_init(t_data *data, char *map_info);
int	    floor_ceil_init(t_data *data, char *map_info);
char	**dup_map(char **map);
void	free_t_map(t_map map_data);
int     flood_fill(char **map_data, int p_x, int p_y);
int     player_data_init(t_data *data);
int	    player_position(t_data *data);

#endif