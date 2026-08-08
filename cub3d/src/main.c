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
        return (0);
    }
    printf("map info\n");
    int i = 0;
    while (data.map.map[i])
    {
        printf("%s", data.map.map[i]);
        i++;
    }
    printf("path texture NO:\n%s\n", data.map.texture_no);
    printf("path texture SO:\n%s\n", data.map.texture_so);
    printf("path texture WE:\n%s\n", data.map.texture_we);
    printf("path texture EA:\n%s\n", data.map.texture_ea);
    printf("floor color:\n%d\n", data.map.color_f);
    printf("ceiling color:\n%d\n", data.map.color_c);
    printf("%d\n", flood_fill(data.map.map, 11, 26));
    return (0);
}