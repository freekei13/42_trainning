/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:26 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/23 17:03:40 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	data		db;
	philo		*philo_db;
	pthread_t	monitor;
	
	if (args_check(ac, av) != 0)
		return (0);
	if (db_parsing(&db, av) != 0)
		return (0);
	philo_db = malloc(sizeof(philo) * db.philo_nb);
	if (!philo_db)
		return (check_mutex(-1, db.philo_nb, &db.forks), 0);
	thread_create(&db, philo_db);
	pthread_create(&monitor, NULL, reaper, &philo_db);
	pthread_join(monitor, NULL);
}
