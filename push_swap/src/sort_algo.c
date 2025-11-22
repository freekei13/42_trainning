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
