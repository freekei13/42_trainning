/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:35:59 by csamakka          #+#    #+#             */
/*   Updated: 2026/02/17 17:06:24 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	db_parsing(data *db, char *av)
{
	int	i;
	
	db = malloc(sizeof(data));
	db->philo_nb = ft_atoi(av);
	db->forks = malloc(sizeof(pthread_mutex_t) * db->philo_nb);
	i = 0;
	while (i < db->philo_nb)
	{
		pthread_mutex_init(&db->forks[i], NULL);
		i++;
	}
}
