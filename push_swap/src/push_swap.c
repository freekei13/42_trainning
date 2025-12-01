/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:17 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/30 19:13:43 by freekei          ###   ########.fr       */
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
	if (size > 5)
		sort_all(stack_a, stack_b);
}
