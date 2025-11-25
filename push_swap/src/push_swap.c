/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:17 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/25 11:15:37 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;
	
	size = ft_lstsize(*stack_a);
	if (size == 2 && (*stack_a)->index != 0)
		swap_a(stack_a);
	if (size == 3)
		three_args_sort(stack_a, stack_b);
	if (size == 4)
		four_args_sort(stack_a, stack_b);
	if (size == 5)
		five_args_sort(stack_a, stack_b);
}
// push_b(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// push_b(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// push_b(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// swap_a(stack_a);
	// print_stacks(*stack_a, *stack_b);
	// swap_b(stack_b);
	// print_stacks(*stack_a, *stack_b);
	// sa_sb(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// rotate_a(stack_a);
	// print_stacks(*stack_a, *stack_b);
	// rotate_b(stack_b);
	// print_stacks(*stack_a, *stack_b);
	// ra_rb(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// re_rotate_a(stack_a);
	// print_stacks(*stack_a, *stack_b);
	// re_rotate_b(stack_b);
	// print_stacks(*stack_a, *stack_b);
	// rra_rrb(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// push_a(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// push_a(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	// push_a(stack_a, stack_b);