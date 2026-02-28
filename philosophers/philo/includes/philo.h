/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:41 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/27 23:47:20 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define MAX_PHILOS	250
# define MSG_ERR_PHILO "Error: Number of philophers must be 2 to %d\n"
# define MSG_ERR_DIGIT	"Error: Arguments must be in digit !\
between 0 and 2147483647.\n"
# define MSG_ERR_NARG	"Error: number of arguments must be 4 or 5.\n\
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define MSG_ERR_INPUT	"Error: There must be more than 1 philosopher.\n"
# define MSG_ERR_THREAD	"Error: Could not create thread.\n"
# define MSG_ERR_MALLOC	"Error: Could not allocate memory.\n"
# define MSG_ERR_MUTEX	"Error: Could not create mutex.\n"

# define MSG_FORK "%ld %d has taken a fork\n"
# define MSG_EAT "%ld %d is eating\n"
# define MSG_SLEEP "%ld %d is sleeping\n"
# define MSG_THINK "%ld %d is thinking\n"
# define MSG_DIE "%ld %d die\n"

typedef struct s_mutex
{
	pthread_mutex_t	p_die;
	pthread_mutex_t	p_print;
}					mutex;

typedef struct s_p_mutex
{
	pthread_mutex_t	last_meal;
	pthread_mutex_t	meal_eaten;
	pthread_mutex_t done_eat;
}					p_mutex;

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
	mutex			db_mutex;
}					data;

typedef struct s_philo
{
	int				id;
	int				fork_right;
	int				fork_left;
	struct	timeval	last_meal;
	int				meal_eaten;
	int				done_eat;
	p_mutex			philo_mutex;
	data			*db;
}					philo;

int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
long	ms_now(struct timeval time_start);
void	mutex_destroy(pthread_mutex_t *mutex, int nb_mutex);

int		args_check(int ac, char **av);

int		db_parsing(data *db, char **av);
void	p_db_parsing(data *db, philo *p_db, int index);

void	simulation_start(data *db, philo *p_db);
#endif