/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:13:26 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/14 17:14:26 by csamakka         ###   ########.fr       */
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

void	*print_(void *id)
{
	int	num;
	
	num = *(int *)id;
	printf("%d is presented\n", num);
	usleep(200);
	printf("%d is terminated\n", num);
	return NULL;
}

int	main(int ac, char **av)
{
	if (args_check(ac, av) == 0)
		return (0);
	
	pthread_t	thread[ft_atoi(av[1])];
	int			i;
	
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_create(&thread[i], NULL, print_, &i);
		i++;
	}
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}