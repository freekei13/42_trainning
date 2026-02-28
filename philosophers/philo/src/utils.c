/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:23:38 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/27 23:45:23 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	if (sign < 0)
		res = res * sign;
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

long	ms_now(struct timeval time_start)
{
	struct timeval 	time_now;
	long			ms;
	long			time_now_ms;
	long			time_start_ms;
	
	gettimeofday(&time_now, NULL);
	time_start_ms = (time_start.tv_sec * 1000) + (time_start.tv_usec / 1000);
	time_now_ms = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	ms = time_now_ms - time_start_ms;
	return (ms);
}

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
