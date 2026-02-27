/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:25:31 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/27 21:20:56 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_db)
{
	philo *p_db;
	
	p_db = (philo *)philo_db;
	while (p_db->db->someone_die == 0 && p_db->done_eat == 0)
	{
		if (p_db->id % 2 == 0)
		{
			pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
			pthread_mutex_lock(&p_db->db->db_mutex.p_print);
			printf(MSG_FORK, ms_now(p_db->db->start_time), p_db->id);
			pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
			pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
			pthread_mutex_lock(&p_db->db->db_mutex.p_print);
			printf(MSG_FORK, ms_now(p_db->db->start_time), p_db->id);
			pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
		}
		else
		{
			pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
			pthread_mutex_lock(&p_db->db->db_mutex.p_print);
			printf(MSG_FORK, ms_now(p_db->db->start_time), p_db->id);
			pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
			pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
			pthread_mutex_lock(&p_db->db->db_mutex.p_print);
			printf(MSG_FORK, ms_now(p_db->db->start_time), p_db->id);
			pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
		}
		pthread_mutex_lock(&p_db->philo_mutex.last_meal);
		gettimeofday(&p_db->last_meal, NULL);
		if (p_db->db->must_eat != -1)
		{
			pthread_mutex_lock(&p_db->philo_mutex.meal_eaten);
			p_db->meal_eaten++;
			pthread_mutex_unlock(&p_db->philo_mutex.meal_eaten);
			if (p_db->db->must_eat == p_db->meal_eaten)
			{
				pthread_mutex_lock(&p_db->philo_mutex.done_eat);
				p_db->done_eat++;
				pthread_mutex_unlock(&p_db->philo_mutex.done_eat);
			}
		}
		pthread_mutex_unlock(&p_db->philo_mutex.last_meal);
		pthread_mutex_lock(&p_db->db->db_mutex.p_print);
		printf(MSG_EAT, ms_now(p_db->db->start_time), p_db->id);
		pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
		usleep(p_db->db->time_to_eat * 1000);
		pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
		pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
		pthread_mutex_lock(&p_db->db->db_mutex.p_print);
		printf(MSG_SLEEP, ms_now(p_db->db->start_time), p_db->id);
		pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
		usleep(p_db->db->time_to_sleep * 1000);
		pthread_mutex_lock(&p_db->db->db_mutex.p_print);
		printf(MSG_THINK, ms_now(p_db->db->start_time), p_db->id);
		pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
	}
	return (NULL);
}

void	*reaper(void *data_share)
{
	data *db;
	
	db = (data *)data_share;
	while (1)
	{
		printf("reaper check someone_die : %d\n", db->someone_die);
		usleep(500 * 1000);
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
		if (i == 0)
			pthread_create(&db->threads[i], NULL, reaper, db);
		else
		{
			p_db_parsing(db, &p_db[i - 1], i);
			if (pthread_create(&db->threads[i], NULL, routine, &p_db[i - 1]) != 0)
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
