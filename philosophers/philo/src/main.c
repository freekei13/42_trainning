/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:26 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/09 22:30:26 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	data		db;
	philo		*philo_db;
	
	if (args_check(ac, av) != 0)
		return (-1);
	if (db_parsing(&db, av) != 0)
		return (-1);
	philo_db = malloc(sizeof(philo) * db.philo_nb);
	if (!philo_db)
	{
		db_cleaner(&db);
		return (ft_putstr_fd(MSG_ERR_MALLOC, 2), -1);
	}
	if (simulation_start(&db, philo_db) != 0)
		return (free(philo_db), -1);
	p_db_cleaner(philo_db, db.philo_nb);
	db_cleaner(&db);
	free(philo_db);
	return (0);
}
