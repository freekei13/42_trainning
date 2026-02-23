/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:41 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/23 17:13:48 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILOS	250
# define MSG_ERR_DIGIT	"Error: Arguments must be in digit !\
between 0 and 2147483647.\n"
# define MSG_ERR_NARG	"Error: number of arguments must be 4 or 5.\n\
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define MSG_ERR_INPUT	"Error: There must be more than 1 philosopher.\n"
# define MSG_ERR_THREAD	"Error: Could not create thread.\n"
# define MSG_ERR_MALLOC	"Error: Could not allocate memory.\n"
# define MSG_ERR_MUTEX	"Error: Could not create mutex.\n"

typedef struct s_data
{
	int				philo_nb;
	pthread_t		*threads;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
	struct	timeval	start_time;
	int				someone_die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	p_die;
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
long	ms_now(struct timeval time_start);

int		db_parsing(data *db, char **av);

void	*routine(void *philo_db);
void	*reaper(void *philo_db);
void	thread_create(data *db, philo *philo_db);

int		args_check(int ac, char **av);
int		check_mutex(int mutex_return, int mutex_num, pthread_mutex_t **mutex);
int		check_thread_create(int thread_return, int thread_num, pthread_t **threads);

#endif