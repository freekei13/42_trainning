/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:20:21 by csamakka          #+#    #+#             */
/*   Updated: 2025/12/15 15:20:23 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_bigger_tab(int old_size, char **old_tab, char *line)
{
	char	**new;
	int		j;

	new = malloc(sizeof(char *) * (2 + old_size));
	j = 0;
	while (old_tab[j] != NULL)
	{
		new[j] = old_tab[j];
		j++;
	}
	new[j] = line;
	new[j + 1] = NULL;
	return (new);
}

char	**map_parse(int fd)
{
	char	*line;
	char	**map;
	char	**new;
	int		i;

	map = malloc(sizeof(char *) * 2);
	line = get_next_line(fd);
	map[0] = line;
	map[1] = NULL;
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = new_bigger_tab(i, map, line);
		free(map);
		map = new;
		i++;
	}
	return (map);
}
