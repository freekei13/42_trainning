/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:26 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/22 02:22:50 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_check(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 7 && ac > 4)
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (ft_isdigit(av[i][j]) == 0)
					return (ft_putstr_fd("Error: Arguments must be in digit !\n", 2), 0);
				j++;
			}
			i++;
		}
		return (1);
	}
	ft_putstr_fd("Error: number of arguments must be 4 or 5\n", 2);
	ft_putstr_fd("./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 2);
	return (0);
}

void	*routine(void *philo_db)
{
	philo			*p_db;
	
	p_db = (philo *)philo_db;
	
	if (p_db->id % 2 == 0)
	{
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
	}
	else
	{
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_right]);
		pthread_mutex_lock(&p_db->db->forks[p_db->fork_left]);
	}
	printf("%ld philo%d is eating\n", ms_now(p_db->db->start_time), p_db->id + 1);
	usleep(p_db->db->time_to_eat * 1000);
	pthread_mutex_unlock(&p_db->db->forks[p_db->fork_right]);
	pthread_mutex_unlock(&p_db->db->forks[p_db->fork_left]);
	printf("%ld philo%d has eaten\n", ms_now(p_db->db->start_time), p_db->id + 1);
	return NULL;
}

void	thread_create(data *db, pthread_t *threads, philo *philo_db)
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
		pthread_create(&threads[i], NULL, routine, &philo_db[i]);
		i++;
	}
	i = 0;
	while (i < db->philo_nb)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	data		db;
	pthread_t	*threads;
	philo		*philo_db;

	if (args_check(ac, av) == 0)
		return (0);
	db_parsing(&db, av);
	threads = malloc(sizeof(pthread_t) * db.philo_nb);
	if (!threads)
		return (0);
	philo_db = malloc(sizeof(philo) * db.philo_nb);
	if (!philo_db)
		return (0);
	thread_create(&db, threads, philo_db);
}