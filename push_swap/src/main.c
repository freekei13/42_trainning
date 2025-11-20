/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:40 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/20 19:25:47 by freekei          ###   ########.fr       */
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
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	arg = input_check(argc, argv);
	if (!error_check(arg))
		return (0);
	a = parse_inputs(arg);
	b = ft_lstnew(1303);
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("a %d --- b %d\n", a->content, b->content);
			a = a->next;
			b = b->next;
		}
		if (a && !b)
		{
			ft_printf("a %d --- b\n", a->content);
			a = a->next;
		}
		if (!a && b)
		{
			ft_printf("a    --- b %d\n", b->content);
			b = b->next;
		}
	}
}