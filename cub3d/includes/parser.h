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
    //vecteur direction
    double  dir_x;
    double  dir_y;
    //vecteur plan camera
    double  plane_x;
    double  plane_y;
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

char    **map_parser(char *map_path);
#endif