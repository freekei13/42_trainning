#include "parser.h"

int main(int ac, char **av)
{
    t_data  data;
    char    **map_info;

    if (ac != 2)
    {
        ft_putstr_fd("Expected a file .cub\n", 2);
        return (0);
    }
    map_info = map_info_parser(av[1]);
    if (!map_info)
        return (0);
    if (map_data_init(&data, map_info) != 0)
    {
        ft_putstr_fd("Map parsing failed !\n", 2);
        free_all(map_info);
        free_t_map(data.map);
        return (0);
    }
    free_all(map_info);
    if (player_data_init(&data) == 1)
    {
        ft_putstr_fd("Player init error\n", 2);
        free_t_map(data.map);
        return (0);
    }
    map_info = dup_map(data.map.map);
    if (flood_fill(map_info, data.player.pos_x, data.player.pos_y) == 1)
    {
        ft_putstr_fd("Map invalid: Player is not surround by wall !\n", 2);
        free_all(map_info);
        free_t_map(data.map);
        return (0);
    }
    free_all(map_info);
    return (0);
}
