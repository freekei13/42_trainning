/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:40 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/18 13:20:48 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arg;
	int		i;
	
	arg = input_check(argc, argv);
	if (!error_check(arg))
		return (1);
	i = 0;
	while (arg[i])
	{
		ft_printf("%s\n", arg[i]);
		i++;
	}
}