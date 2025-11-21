/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:17 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/21 18:38:32 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	swap_a(stack_a);
	swap_b(stack_b);
	sa_sb(stack_a, stack_b);
}