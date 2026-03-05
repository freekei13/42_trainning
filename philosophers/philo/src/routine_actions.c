/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 01:43:32 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/05 18:26:49 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_simulation(philo *p_db)
{
	pthread_mutex_lock(&p_db->db->db_mutex.p_die);
	if (p_db->db->someone_die > 0 || p_db->db->all_full >= p_db->db->philo_nb)
	{
		pthread_mutex_unlock(&p_db->db->db_mutex.p_die);
		return (-1);
	}
	pthread_mutex_unlock(&p_db->db->db_mutex.p_die);
	return (0);
}

void	printing_philo(philo *p_db, char *message)
{
	pthread_mutex_lock(&p_db->db->db_mutex.p_print);
	printf(message, ms_now(p_db->db->start_time), p_db->id);
	pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
}

int	taking_forks(philo *p_db)
{
	if (p_db->id % 2 != 0)
	{
		usleep(p_db->db->time_to_eat / 10);
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
		if (stop_simulation(p_db) == -1)
		{
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
			return (-1);
		}
		printing_philo(p_db, MSG_FORK);
		if (p_db->db->philo_nb == 1)
		{
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
			return (-1);
		}
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
		if (stop_simulation(p_db) == -1)
		{
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
			return (-1);
		}
		printing_philo(p_db, MSG_FORK);
	}
	else
	{
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
		if (stop_simulation(p_db) == -1)
		{
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
			return (-1);
		}
		printing_philo(p_db, MSG_FORK);
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
		if (stop_simulation(p_db) == -1)
		{
			pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
			return (-1);
		}
		printing_philo(p_db, MSG_FORK);
	}
	return (0);
}

void	eating_philo(philo *p_db)
{
	pthread_mutex_lock(&p_db->philo_mutex.last_meal);
	gettimeofday(&p_db->last_meal, NULL);
	pthread_mutex_unlock(&p_db->philo_mutex.last_meal);
	printing_philo(p_db, MSG_EAT);
	usleep(p_db->db->time_to_eat * 1000);
	pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
	pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
	if (p_db->db->must_eat != -1)
	{
		pthread_mutex_lock(&p_db->philo_mutex.meal_eaten);
		p_db->meal_eaten++;
		pthread_mutex_unlock(&p_db->philo_mutex.meal_eaten);
	}
}
