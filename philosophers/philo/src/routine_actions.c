/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 01:43:32 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/03 15:50:52 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printing_philo(philo *p_db, char *message)
{
	pthread_mutex_lock(&p_db->db->db_mutex.p_print);
	printf(message, ms_now(p_db->db->start_time), p_db->id);
	pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
}

void	taking_forks(philo *p_db)
{
	if (p_db->id % 2 != 0)
	{
		usleep(p_db->db->time_to_eat / 10);
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
		printing_philo(p_db, MSG_FORK);
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
		printing_philo(p_db, MSG_FORK);
	}
	else
	{
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
		printing_philo(p_db, MSG_FORK);
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
		printing_philo(p_db, MSG_FORK);
	}
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

int	someone_die(philo *p_db)
{
	pthread_mutex_lock(&p_db->db->db_mutex.p_die);
	if (p_db->db->someone_die > 0)
	{
		pthread_mutex_unlock(&p_db->db->db_mutex.p_die);
		return (-1);
	}
	pthread_mutex_unlock(&p_db->db->db_mutex.p_die);
	return (0);
}

int	someone_full(philo *p_db)
{
	pthread_mutex_lock(&p_db->philo_mutex.done_eat);
	if (p_db->done_eat > 0)
	{
		pthread_mutex_unlock(&p_db->philo_mutex.done_eat);
		return (-1);
	}
	pthread_mutex_unlock(&p_db->philo_mutex.done_eat);
	return (0);
}
