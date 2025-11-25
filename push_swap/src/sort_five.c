/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:46:40 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/25 11:15:58 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_second_min(t_list *stack_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index == 1)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void	pre_sort_five(t_list	**stack_a, t_list **stack_b, int min)
{
	if (min == 4)
		re_rotate_a(stack_a);
	else if (min == 3)
	{
		re_rotate_a(stack_a);
		re_rotate_a(stack_a);
	}
	else if (min == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min == 1)
		swap_a(stack_a);
	push_b(stack_a, stack_b);
}

void	five_args_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int second_min;

	min = find_min(*stack_a);
	pre_sort_five(stack_a, stack_b, min);
	second_min = find_second_min(*stack_a);
	pre_sort_five(stack_a, stack_b, second_min);
	three_args_sort_five(stack_a, stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}