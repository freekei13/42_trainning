#include "parser.h"

char   **parser_construct(int fd)
{
    int     i;
    char    *map_read;
    char    **map;

    map = NULL;
    i = 0;
    while (1)
    {
        map_read = get_next_line(fd);
        if (!map_read)
            break ;
        map = realloc(map, sizeof(char *) * (2 + i));
        if (!map)
            return (NULL);
        map[i] = ft_strdup(map_read);
        map[i + 1] = NULL;
        free(map_read);
        i++;
    }
    return (map);
}

char    **map_parser(char *map_path)
{
    int     path_len;
    int     fd;
    char    **map;

    path_len = ft_strlen(map_path);
    if (ft_strncmp(map_path + path_len - 4, ".cub", 5) != 0)
    {
        ft_putstr_fd("Path invalid\n", 2);
        return (NULL);
    }
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    map = parser_construct(fd);
    if (!map)
        return (NULL);
    return (map);
}
