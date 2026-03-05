/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:26 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/05 19:38:18 by csamakka         ###   ########.fr       */
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
	simulation_start(&db, philo_db);
	p_db_cleaner(philo_db, db.philo_nb);
	db_cleaner(&db);
	free(philo_db);
	return (0);
}
