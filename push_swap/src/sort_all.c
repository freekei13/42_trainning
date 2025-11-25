/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:27:07 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/25 14:17:29 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	b_size;

	size = ft_lstsize(*stack_a);
	b_size = size - 3;
	while (b_size != 0)
	{
		push_b(stack_a, stack_b);
		b_size--;
	}
}