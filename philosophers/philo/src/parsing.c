/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:35:59 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/26 23:50:13 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_inits(pthread_mutex_t **mutex)
{
	int	i;
	
	i = 0;
	while (mutex[i])
	{
		if (pthread_mutex_init(mutex[i], NULL) != 0)
		{
			mutex_destroy(*mutex, i);
			ft_putstr_fd(MSG_ERR_MUTEX, 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	db_parsing(data *db, char **av)
{
	db->philo_nb = ft_atol(av[1]);
	db->time_to_die = ft_atol(av[2]);
	db->time_to_eat = ft_atol(av[3]);
	db->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		db->must_eat = ft_atol(av[5]);
	else
		db->must_eat = -1;
	db->someone_die = 0;
	db->threads = malloc(sizeof(pthread_t) * (db->philo_nb + 1));
	if (!db->threads)
		return (ft_putstr_fd(MSG_ERR_MALLOC, 2), -1);
	db->forks = malloc(sizeof(pthread_mutex_t) * db->philo_nb);
	if (!db->forks)
		return (ft_putstr_fd(MSG_ERR_MALLOC, 2), free(db->threads), -1);
	if (mutex_inits(&db->forks) != 0)
		return (free(db->threads), free(db->forks), -1);
	if (pthread_mutex_init(&db->p_die, NULL) != 0)
	{
		mutex_destroy(db->forks, db->philo_nb);
		pthread_mutex_destroy(&db->p_die);
		ft_putstr_fd(MSG_ERR_MUTEX, 2);
		return (free(db->threads), free(db->forks), -1);
	}
	return (0);
}

void	p_db_parsing(data *db, philo *p_db, int index)
{
	p_db->id = index;
	p_db->fork_right = index % db->philo_nb;
	p_db->fork_left = index - 1;
	gettimeofday(&p_db->time_born, NULL);
	gettimeofday(&p_db->last_meal, NULL);
	p_db->meal_eaten = 0;
	p_db->db = db;
}
