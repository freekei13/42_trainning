/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:40:40 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/25 11:14:23 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_args_sort(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index == 0 && (*stack_a)->next->index == 2)
	{
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_a(stack_a, stack_b);
	}
	if ((*stack_a)->index == 1 && (*stack_a)->next->index == 2)
		re_rotate_a(stack_a);
	if ((*stack_a)->index == 1 && (*stack_a)->next->index == 0)
		swap_a(stack_a);
	if ((*stack_a)->index == 2 && (*stack_a)->next->index == 1)
	{
		swap_a(stack_a);
		re_rotate_a(stack_a);
	}
	if ((*stack_a)->index == 2 && (*stack_a)->next->index == 0)
		rotate_a(stack_a);
}

void	three_args_sort_four(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index == 1 && (*stack_a)->next->index == 3)
	{
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_a(stack_a, stack_b);
	}
	if ((*stack_a)->index == 2 && (*stack_a)->next->index == 3)
		re_rotate_a(stack_a);
	if ((*stack_a)->index == 2 && (*stack_a)->next->index == 1)
		swap_a(stack_a);
	if ((*stack_a)->index == 3 && (*stack_a)->next->index == 2)
	{
		swap_a(stack_a);
		re_rotate_a(stack_a);
	}
	if ((*stack_a)->index == 3 && (*stack_a)->next->index == 1)
		rotate_a(stack_a);
}

void	three_args_sort_five(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index == 2 && (*stack_a)->next->index == 4)
	{
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_a(stack_a, stack_b);
	}
	if ((*stack_a)->index == 3 && (*stack_a)->next->index == 4)
		re_rotate_a(stack_a);
	if ((*stack_a)->index == 3 && (*stack_a)->next->index == 2)
		swap_a(stack_a);
	if ((*stack_a)->index == 4 && (*stack_a)->next->index == 3)
	{
		swap_a(stack_a);
		re_rotate_a(stack_a);
	}
	if ((*stack_a)->index == 4 && (*stack_a)->next->index == 2)
		rotate_a(stack_a);
}