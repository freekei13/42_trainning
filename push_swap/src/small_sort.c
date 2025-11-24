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

int		find_min(t_list *stack_a)
{

}

int		find_second_min(t_list *stack_a)
{

}

void	four_args_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	//if min == 0, 1, 2, 3
	//do operations
	three_args_sort(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	five_args_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int second_min;

	min = find_min(*stack_a);
	seconde_min = find_second_min(*stack_a);
	//if min == 0, 1, 2, 3, 4
	//do operations
	three_args_sort(stack_a, stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}