/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:20:09 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/18 16:24:21 by csamakka         ###   ########.fr       */
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
			if (j == 0 && (inputs[i][j] == '-' || inputs[i][j] == '+'))
			{
				if (ft_strlen(inputs[i]) == 1)
					return (ft_printf("ERROR"), 0);
				while (inputs[i][j + 1])
				{
					if (!ft_isdigit(inputs[i][j + 1]))
						return (ft_printf("ERROR"), 0);
					j++;
				}
				break ;
			}
			if (!ft_isdigit(inputs[i][j]))
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
	int		i;
	char	*tmp;
	
	if (ac < 2)
		return (0);
	if (ac == 2)
		arg = ft_split(av[1], 32);
	if (ac > 2)
	{
		tmp = ft_strdup("");
		i = 1;
		while (av[i])
		{
			tmp = ft_strjoin(tmp, av[i]);
			tmp = ft_strjoin(tmp, " ");
			i++;
		}
		arg = ft_split(tmp, 32);
		free(tmp);
		tmp = NULL;
	}
	return (arg);
}
