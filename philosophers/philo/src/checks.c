/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:27:44 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/22 21:05:06 by csamakka         ###   ########.fr       */
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
					return (ft_putstr_fd(MSG_ERR_DIGIT, 2), 0);
				j++;
			}
			i++;
		}
		return (0);
	}
	ft_putstr_fd(MSG_ERR_NARG, 2);
	return (-1);
}

int	check_mutex(int mutex_return, int mutex_num, pthread_mutex_t **mutex)
{
	int	i;
	
	if (mutex_return != 0)
	{
		i = 0;
		while (i < mutex_num)
		{
			pthread_mutex_destroy(mutex[i]);
			i++;
		}
		free(mutex);
		return (-1);
	}
	return (0);
}

int	check_thread_create(int thread_return, int thread_num, pthread_t **threads)
{
	int	i;
	
	if (thread_return != 0)
	{
		i = 0;
		while (i < thread_num)
		{
			pthread_join(*threads[i], NULL);
			i++;
		}
		free(threads);
		return (-1);
	}
	return (0);
}
