/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:25:31 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/02 02:37:15 by csamakka         ###   ########.fr       */
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
		usleep(500);
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
		if (p_db[i].db->all_full == p_db[i].db->philo_nb)
			return (NULL);
		pthread_mutex_lock(&p_db[i].philo_mutex.done_eat);
		if (p_db[i].done_eat == 0)
		{
			pthread_mutex_unlock(&p_db[i].philo_mutex.done_eat);
			pthread_mutex_lock(&p_db[i].philo_mutex.last_meal);
			if (ms_now(p_db[i].last_meal) >= p_db[i].db->time_to_die)
			{
				pthread_mutex_unlock(&p_db[i].philo_mutex.last_meal);
				pthread_mutex_lock(&p_db[i].db->db_mutex.p_die);
				p_db[i].db->someone_die++;
				pthread_mutex_unlock(&p_db[i].db->db_mutex.p_die);
				pthread_mutex_lock(&p_db[i].db->db_mutex.p_print);
				printf(MSG_DIE, ms_now(p_db[i].db->start_time), p_db[i].id);
				pthread_mutex_unlock(&p_db[i].db->db_mutex.p_print);
				return (NULL);
			}
			pthread_mutex_unlock(&p_db[i].philo_mutex.last_meal);
			pthread_mutex_lock(&p_db[i].philo_mutex.meal_eaten);
			if (p_db[i].meal_eaten >= p_db[i].db->must_eat && p_db[i].db->must_eat != -1)
			{
				pthread_mutex_unlock(&p_db[i].philo_mutex.meal_eaten);
				pthread_mutex_lock(&p_db[i].philo_mutex.done_eat);
				p_db[i].done_eat++;
				p_db[i].db->all_full++;
				pthread_mutex_unlock(&p_db[i].philo_mutex.done_eat);
			}
			else
				pthread_mutex_unlock(&p_db[i].philo_mutex.meal_eaten);
		}
		else
			pthread_mutex_unlock(&p_db[i].philo_mutex.done_eat);
		if (i == p_db[i].db->philo_nb - 1)
		{
			i = 0;
			usleep(1000);
		}
		else
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
