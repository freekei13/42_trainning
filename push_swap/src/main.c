/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:40 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/17 16:00:36 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arg;
	int		i;
	
	arg = input_check(argc, argv);
	if (error_check(arg) == 0)
		return (0);
	i = 0;
	while (arg[i])
	{
		ft_printf("%s\n", arg[i]);
		i++;
	}
}