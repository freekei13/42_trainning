/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:35:59 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/23 16:09:17 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	db_parsing(data *db, char **av)
{
	int	i;
	
	gettimeofday(&db->start_time, NULL);
	db->philo_nb = ft_atol(av[1]);
	db->threads = malloc(sizeof(pthread_t) * db->philo_nb);
	if (!db->threads)
		return (ft_putstr_fd(MSG_ERR_MALLOC, 2), -1);
	db->time_to_die = ft_atol(av[2]);
	db->time_to_eat = ft_atol(av[3]);
	db->time_to_sleep = ft_atol(av[4]);
	if (!av[5])
		db->must_eat = -1;
	else
		db->must_eat = ft_atol(av[5]);
	db->someone_die = 0;
	db->forks = malloc(sizeof(pthread_mutex_t) * db->philo_nb);
	if (!db->forks)
		return (free(db->threads), ft_putstr_fd(MSG_ERR_MALLOC, 2), -1);
	i = -1;
	while (++i < db->philo_nb)
		if (check_mutex(pthread_mutex_init(&db->forks[i], NULL), i + 1, &db->forks) != 0)
			return (free(db->threads), free(db->forks), ft_putstr_fd(MSG_ERR_MUTEX, 2), -1);
	if (pthread_mutex_init(&db->p_die, NULL) != 0)
			return (free(db->threads), check_mutex(-1, 1, &db->forks),
				ft_putstr_fd(MSG_ERR_MUTEX, 2), -1);
	return (0);
}
