/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:39:59 by csamakka          #+#    #+#             */
/*   Updated: 2026/03/05 20:32:10 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy(pthread_mutex_t *mutex, int nb_mutex)
{
	int	i;

	i = 0;
	while (i < nb_mutex)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
}

void	threads_join(pthread_t *threads, int nb_threads)
{
	int	i;

	i = 0;
	while (i < nb_threads)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
void	db_cleaner(data *db)
{
	mutex_destroy(db->forks, db->philo_nb);
	pthread_mutex_destroy(&db->db_mutex.p_die);
	pthread_mutex_destroy(&db->db_mutex.p_print);
	free(db->forks);
	free(db->threads);
}

void	p_db_cleaner(philo *p_db, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&p_db[i].philo_mutex.last_meal);
		pthread_mutex_destroy(&p_db[i].philo_mutex.meal_eaten);
		pthread_mutex_destroy(&p_db[i].philo_mutex.done_eat);
		i++;
	}
}
