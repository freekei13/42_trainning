#include "push_swap.h"

int		find_min(t_list *stack_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index == 0)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void	pre_sort_four(t_list **stack_a, t_list **stack_b, int min)
{
	if (min == 3)
		re_rotate_a(stack_a);
	else if (min == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min == 1)
		swap_a(stack_a);
	push_b(stack_a, stack_b);
}

void	four_args_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	pre_sort_four(stack_a, stack_b, min);
	three_args_sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
