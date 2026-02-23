/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:25:31 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/23 17:41:31 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_db)
{
	philo			*p_db;
	
	p_db = (philo *)philo_db;
	while (p_db->db->someone_die == 0)
	{
		if (ms_now(p_db->last_meal) > p_db->db->time_to_die - p_db->db->time_to_eat)
			break ;
		if (p_db->db->someone_die == 0)
		{
			if (p_db->id % 2 == 0)
			{
				pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
				printf("%ld %d has taken a fork\n", ms_now(p_db->db->start_time), p_db->id + 1);
				pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
				printf("%ld %d has taken a fork\n", ms_now(p_db->db->start_time), p_db->id + 1);
			}
			else
			{
				pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
				printf("%ld %d has taken a fork\n", ms_now(p_db->db->start_time), p_db->id + 1);
				pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
				printf("%ld %d has taken a fork\n", ms_now(p_db->db->start_time), p_db->id + 1);
			}
			printf("%ld %d is eating\n", ms_now(p_db->db->start_time), p_db->id + 1);
			usleep(p_db->db->time_to_eat * 1000);
			gettimeofday(&p_db->last_meal, NULL);
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
			if (p_db->db->someone_die == 0)
			{
				printf("%ld %d is sleeping\n", ms_now(p_db->db->start_time), p_db->id + 1);
				usleep(p_db->db->time_to_sleep * 1000);
			}
		}
		if (p_db->db->someone_die == 0)
			printf("%ld %d is thinking\n", ms_now(p_db->db->start_time), p_db->id + 1);
	}
	return NULL;
}
void	*reaper(void *philo_db)
{
	int		i;
	philo	**p_db;
	
	p_db = (philo **)philo_db;
	i = 0;
	while (1)
	{
		if (i >= p_db[0]->db->philo_nb)
			i = 0;
		if (ms_now(p_db[i]->last_meal) > p_db[i]->db->time_to_die)
		{
			pthread_mutex_lock(&p_db[i]->db->p_die);
			p_db[i]->db->someone_die++;
			printf("%ld %d died\n", ms_now(p_db[i]->db->start_time), p_db[i]->id + 1);
			pthread_mutex_unlock(&p_db[i]->db->p_die);
			break ;
		}
		i++;
	}
	return (NULL);
}

void	thread_create(data *db, philo *philo_db)
{
	int	i;

	i = 0;
	while (i < db->philo_nb)
	{
		philo_db[i].id = i;
		philo_db[i].fork_left = i;
		philo_db[i].fork_right = (i + 1) % db->philo_nb;
		gettimeofday(&philo_db[i].last_meal, NULL);
		philo_db[i].meal_eaten = 0;
		philo_db[i].db = db;
		if (check_thread_create(pthread_create(&db->threads[i], NULL, routine, &philo_db[i]), i + 1, &db->threads) != 0)
			return (ft_putstr_fd(MSG_ERR_THREAD, 2));
		i++;
	}
	i = 0;
	while (i < db->philo_nb)
	{
		pthread_join(db->threads[i], NULL);
		i++;
	}
}
