#include "parser.h"

int main(int ac, char **av)
{
    t_data  data;

    if (ac != 2)
    {
        ft_putstr_fd("Expected 1 argument\n", 2);
        return (0);
    }
    data.map.map = map_parser(av[1]);
    int i = 0;
    while (data.map.map[i])
    {
        printf("%s", data.map.map[i]);
        i++;
    }
    return (0);
}