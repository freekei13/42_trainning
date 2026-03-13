/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:06:58 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/10 12:03:08 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking_philo(t_philo *p_db)
{
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
