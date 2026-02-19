/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:41 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/19 23:34:50 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	long			philo_nb;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
	struct	timeval	start_time;
	int				someone_die;
	pthread_mutex_t	*forks;
}					data;

typedef struct s_philo
{
	int				id;
	int				fork_right;
	int				fork_left;
	struct	timeval	last_meal;
	int				meal_eaten;
	data			*db;
}					philo;

int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
void	ft_putstr_fd(char *s, int fd);

void	db_parsing(data *db, char **av);

#endif