/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:25:31 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/02 20:45:35 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_db)
{
	philo *p_db;
	
	p_db = (philo *)philo_db;
	while (1)
	{
		if (someone_die(p_db) != 0 || someone_full(p_db) != 0)
			return (NULL);
		taking_forks(p_db);
		eating_philo(p_db);
		printing_philo(p_db, MSG_SLEEP);
		usleep(p_db->db->time_to_sleep * 1000);
		printing_philo(p_db, MSG_THINK);
		pthread_mutex_lock(&p_db->philo_mutex.last_meal);
		p_db->time_to_think = (p_db->db->time_to_die
				- ms_now(p_db->last_meal)
				- p_db->db->time_to_eat) / 2;
		pthread_mutex_unlock(&p_db->philo_mutex.last_meal);
		if (p_db->time_to_think <= 0)
			p_db->time_to_think = 0;
		usleep(p_db->time_to_think * 1000);
	}
	return (NULL);
}

void	*reaper(void *philo_db)
{
	philo	*p_db;
	int		i;
	
	p_db = (philo *)philo_db;
	i = 0;
	while (1)
	{
		if (reaper_monitor(&p_db[i]) != 0)
			return (NULL);
		if (i == p_db[i].db->philo_nb - 1)
		{
			i = 0;
			usleep(1000);
		}
		i++;
	}
	return (NULL);
}

void	simulation_start(data *db, philo *p_db)
{
	int i;

	gettimeofday(&db->start_time, NULL);
	i = 0;
	while (i < db->philo_nb + 1)
	{
		if (i == db->philo_nb)
			pthread_create(&db->threads[i], NULL, reaper, p_db);
		else
		{
			p_db_parsing(db, &p_db[i], i);
			if (pthread_create(&db->threads[i], NULL, routine, &p_db[i]) != 0)
				return (void)(ft_putstr_fd(MSG_ERR_THREAD, 2));//free threads  et p_db
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
