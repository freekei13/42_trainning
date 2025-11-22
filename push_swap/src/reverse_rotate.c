/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:56 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/22 14:07:51 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rotate_a(t_list **stack_a)
{
	t_list	*second_last;
	t_list	*last;
	
	second_last = *stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}
