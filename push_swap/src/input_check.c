/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:20:09 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/30 19:01:21 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_minmax_check(char **inputs)
{
	long long	res;
	long long	limit;
	char		*str;

	while (*inputs)
	{
		res = 0;
		limit = INT_MAX;
		str = *inputs;
		if (*str == '-' || *str == '+')
		{
			if (*str++ == '-')
				limit = (long long)INT_MAX + 1;
		}
		while (*str)
		{
			if (res > limit / 10
				|| (res == limit / 10 && (*str - '0') > limit % 10))
				return (0);
			res = res * 10 + (*str - '0');
			str++;
		}
		inputs++;
	}
	return (1);
}

int	repeat_check(char **inputs)
{
	int	i;
	int	j;

	i = 0;
	while (inputs[i])
	{
		j = 1;
		while (inputs[j + i])
		{
			if (ft_memcmp(inputs[i], inputs[j + i], 12) != 0)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	digit_check(char **inputs)
{
	int	i;
	int	j;

	i = 0;
	while (inputs[i])
	{
		j = 0;
		if ((inputs[i][0] == '-' || inputs[i][0] == '+')
			&& inputs[i][1] == '\0')
			return (0);
		while (inputs[i][j])
		{
			if (j == 0 && (inputs[i][0] == '-' || inputs[i][0] == '+'))
				j++;
			if (!ft_isdigit(inputs[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*join_args(char **av)
{
	int		i;
	char	*tmp;
	char	*join;

	tmp = ft_strdup("");
	i = 1;
	while (av[i])
	{
		join = ft_strjoin(tmp, av[i]);
		free(tmp);
		tmp = join;
		join = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = join;
		i++;
	}
	return (tmp);
}

char	**input_check(int ac, char *av[])
{
	char	**arg;
	char	*tmp;

	if (ac < 2)
		return (NULL);
	if (ac == 2)
		arg = ft_split(av[1], 32);
	if (ac > 2)
	{
		tmp = join_args(av);
		arg = ft_split(tmp, 32);
		free(tmp);
		tmp = NULL;
	}
	return (arg);
}
