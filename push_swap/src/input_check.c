/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:20:09 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/17 16:12:13 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(char **inputs)
{
	int	i;
	int	j;

	i = 0;
	while (inputs[i])
	{
		j = 0;
		while (inputs[i][j])
		{
			if (ft_isdigit(inputs[i][j]) == 0)
				return (ft_printf("ERROR"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**input_check(int ac, char *av[])
{
	char	**arg;
	
	if (ac < 2)
		return (0);
	if (ac == 2)
		arg = ft_split(av[1], 32);
	else
		arg = av;
	return (arg);
}