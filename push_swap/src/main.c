/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:40 by csamakka          #+#    #+#             */
/*   Updated: 2025/12/01 17:22:39 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("a %d index %d --- b %d index %d\n",
				a->content, a->index, b->content, b->index);
			a = a->next;
			b = b->next;
		}
		if (a && !b)
		{
			ft_printf("a %d index %d --- b\n", a->content, a->index);
			a = a->next;
		}
		if (!a && b)
		{
			ft_printf("a           --- b %d index %d\n", b->content, b->index);
			b = b->next;
		}
	}
}

int	error_check(char **inputs)
{
	if (!inputs)
		return (0);
	else if (digit_check(inputs)
		&& repeat_check(inputs)
		&& int_minmax_check(inputs))
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
		return (free_all(arg), 0);
	a = parse_inputs(arg);
	free_all(arg);
	index_assign(a);
	push_swap(&a, &b);
	free_lst(&a);
	free_lst(&b);
}
