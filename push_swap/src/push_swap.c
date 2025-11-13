/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:17 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/13 16:17:46 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**arg;
	int		i;
	
	if (argc < 2)
		return (0);
	if (argc == 2)
		arg = ft_split(argv[1], 32);
	i = 0;
	while (arg[i++])
		ft_printf("%s\n", arg[i]);
	return (0);
}