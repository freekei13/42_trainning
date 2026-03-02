/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:36:08 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/02 20:15:24 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_die_check(philo *p_db)
{
	pthread_mutex_lock(&p_db->philo_mutex.last_meal);
	if (ms_now(p_db->last_meal) >= p_db->db->time_to_die)
	{
		pthread_mutex_unlock(&p_db->philo_mutex.last_meal);
		pthread_mutex_lock(&p_db->db->db_mutex.p_die);
		p_db->db->someone_die++;
		pthread_mutex_unlock(&p_db->db->db_mutex.p_die);
		pthread_mutex_lock(&p_db->db->db_mutex.p_print);
		printf(MSG_DIE, ms_now(p_db->db->start_time), p_db->id);
		pthread_mutex_unlock(&p_db->db->db_mutex.p_print);
		return (-1);
	}
	pthread_mutex_unlock(&p_db->philo_mutex.last_meal);
	return (0);
}

int	someone_full_check(philo *p_db)
{
	pthread_mutex_lock(&p_db->philo_mutex.meal_eaten);
	if (p_db->meal_eaten >= p_db->db->must_eat && p_db->db->must_eat != -1)
	{
		pthread_mutex_unlock(&p_db->philo_mutex.meal_eaten);
		pthread_mutex_lock(&p_db->philo_mutex.done_eat);
		p_db->done_eat++;
		p_db->db->all_full++;
		pthread_mutex_unlock(&p_db->philo_mutex.done_eat);
		if (p_db->db->all_full >= p_db->db->philo_nb)
			return (-1);
		else
			return (0);
	}
	pthread_mutex_unlock(&p_db->philo_mutex.meal_eaten);
	return (0);
}

int	reaper_monitor(philo *p_db)
{
	pthread_mutex_lock(&p_db->philo_mutex.done_eat);
	if (p_db->done_eat == 0)
	{
		pthread_mutex_unlock(&p_db->philo_mutex.done_eat);
		if (someone_die_check(p_db) == -1)
			return (-1);
		if (someone_full_check(p_db) == -1)
			return (-1);
	}
	else
		pthread_mutex_unlock(&p_db->philo_mutex.done_eat);
	return (0);
}
