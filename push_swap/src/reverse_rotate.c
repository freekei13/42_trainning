/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:56 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/22 21:58:47 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rotate_a(t_list **stack_a)
{
	t_list	*second_last;
	t_list	*last;
	
	if(ft_lstsize(*stack_a) < 2)
		return ;
	second_last = *stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}

void	re_rotate_b(t_list **stack_b)
{
	t_list	*second_last;
	t_list	*last;
	
	if(ft_lstsize(*stack_b) < 2)
		return ;
	second_last = *stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
}

void	rra_rrb(t_list **stack_a, t_list **stack_b)
{
	t_list	*second_last_a;
	t_list	*last_a;
	t_list	*second_last_b;
	t_list	*last_b;

	if(ft_lstsize(*stack_a) > 1)
	{
		second_last_a = *stack_a;
		while (second_last_a->next->next)
			second_last_a = second_last_a->next;
		last_a = second_last_a->next;
		second_last_a->next = NULL;
		last_a->next = *stack_a;
		*stack_a = last_a;
	}
	if(ft_lstsize(*stack_b) > 1)
	{
		second_last_b = *stack_b;
		while (second_last_b->next->next)
			second_last_b = second_last_b->next;
		last_b = second_last_b->next;
		second_last_b->next = NULL;
		last_b->next = *stack_b;
		*stack_b = last_b;
	}
	ft_printf("rrr\n");
}
