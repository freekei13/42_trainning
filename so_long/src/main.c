/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:20:05 by csamakka          #+#    #+#             */
/*   Updated: 2026/01/20 14:04:39 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_data	data;

	if (argc > 2 || argc < 2)
		return (write(2, "Pls enter a map's path\n", 23), 0);
	map = map_check(argv[1]);
	if (!map)
		return (0);
	data = set_data(map);
	map_render(&data);
	mlx_hook(data.window, 2, 1L << 0, key_actions, &data);
	mlx_hook(data.window, 17, 0, exit_game, &data);
	mlx_loop(data.mlx);
}
