/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:40 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/20 14:20:52 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(char **inputs)
{
	if (!inputs)
		return (0);
	else if (digit_check(inputs) && repeat_check(inputs) && int_minmax_check(inputs))
		return (1);
	else
		return (ft_printf("Error\n"), 0);
}

int	main(int argc, char **argv)
{
	char	**arg;
	int		i;
	
	arg = input_check(argc, argv);
	if (!error_check(arg))
		return (0);
	i = 0;
	while (arg[i])
	{
		ft_printf("%s\n", arg[i]);
		i++;
	}
}