/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:27:07 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/25 22:37:32 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min;
	int	mid;
	int	max;

	size = ft_lstsize(*stack_a);
	min = 0;
	mid = size / 2;
	max = size - 1;
	while (1)
	{
		if (ft_lstsize(*stack_a) == 3)
			break ;
		if ((*stack_a)->index == min || (*stack_a)->index == mid
			|| (*stack_a)->index == max)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
	}
	three_args_sort(stack_a, stack_b);
}