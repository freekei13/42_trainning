/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:25:31 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/26 23:56:30 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_db)
{
	philo *p_db;
	
	p_db = (philo *)philo_db;
	printf("id : %d\n\
fork_right : %d\n\
fork_left : %d\n\
time_born : %ld\n\
last_meal : %ld\n\
meal_eaten : %d\n\
philo_nb : %d\n", p_db->id, p_db->fork_right, p_db->fork_left,
		p_db->time_born.tv_usec, p_db->last_meal.tv_usec, p_db->meal_eaten, p_db->db->philo_nb);
	return (NULL);
}
void	*reaper(void *data_share)
{
	data *db;
	
	db = (data *)data_share;
	printf("reaper check someone_die : %d\n", db->someone_die);
	return (NULL);
}

void	simulation_start(data *db, philo **p_db)
{
	int i;

	i = 0;
	while (i < db->philo_nb + 1)
	{
		if (i == 0)
			pthread_create(&db->threads[i], NULL, reaper, db);
		else
		{
			p_db_parsing(db, p_db[i - 1], i);
			pthread_create(&db->threads[i], NULL, routine, p_db[i - 1]);
		}
		i++;
	}
	i = 0;
	while (i < db->philo_nb + 1)
	{
		pthread_join(db->threads[i], NULL);
		i++;
	}
}
