/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:35:59 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/22 02:21:03 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	db_parsing(data *db, char **av)
{
	int	i;
	
	gettimeofday(&db->start_time, NULL);
	db->philo_nb = ft_atol(av[1]);
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
		return ;
	i = 0;
	while (i < db->philo_nb)
	{
		pthread_mutex_init(&db->forks[i], NULL);
		i++;
	}
}
