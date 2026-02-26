/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:26 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/26 19:26:40 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	data		db;
	// philo		*philo_db;
	
	if (args_check(ac, av) != 0)
		return (-1);
	if (db_parsing(&db, av) != 0)
		return (-1);
	return (0);
}
