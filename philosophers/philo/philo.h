/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:41 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/17 14:23:43 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data
{
	int				philo_nb;
	pthread_mutex_t	*forks;
}					data;

typedef struct s_philo
{
	int		id;
	int		fork_right;
	int		fork_left;
	int		time_to_die;
	long	last_meal;
	int		must_eat;
}			philo;

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);

#endif