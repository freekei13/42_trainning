/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:27:44 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/26 15:42:39 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int digits_check(char **av)
{
	int		i;
	int		j;
	long	arg;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (-1);
			j++;
		}
		arg = ft_atol(av[i]);
		if (arg > (long)INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int	args_check(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (ft_putstr_fd(MSG_ERR_NARG, 2), -1);
	if (digits_check(av) == -1)
		return (ft_putstr_fd(MSG_ERR_DIGIT, 2), -1);
	if (ft_atol(av[1]) < 2 || ft_atol(av[1]) > MAX_PHILOS)
		return (printf(MSG_ERR_PHILO, MAX_PHILOS));
	return (0);
}
