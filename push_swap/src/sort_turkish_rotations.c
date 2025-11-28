#include "push_swap.h"

void	scena_rr(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;

	i = -1;
	if (pos_a > pos_b)
	{
		while (++i < pos_b)
			ra_rb(a, b);
		i = -1;
		while (++i < pos_a - pos_b)
			rotate_a(a);
	}
	else if (pos_a < pos_b)
	{
		while (++i < pos_a)
			ra_rb(a, b);
		i = -1;
		while (++i < pos_b - pos_a)
			rotate_b(b);
	}
	else
	{
		while (++i < pos_a)
			ra_rb(a, b);
	}
}

void	scena_rrr(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;

	i = -1;
	if (pos_a > pos_b)
	{
		while (++i < pos_b)
			rra_rrb(a, b);
		i = -1;
		while (++i < pos_a - pos_b)
			re_rotate_a(a);
	}
	else if (pos_a < pos_b)
	{
		while (++i < pos_a)
			rra_rrb(a, b);
		i = -1;
		while (++i < pos_b - pos_a)
			re_rotate_b(b);
	}
	else
	{
		while (++i < pos_a)
			rra_rrb(a, b);
	}
}

void	scena_ra_rrb(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;
	int	size_b;

	i = -1;
	size_b = ft_lstsize(*b);
	if (pos_b >= size_b)
    	return ;
	while (++i < pos_a)
		rotate_a(a);
	i = -1;
	while (++i <  size_b - pos_b)
		re_rotate_b(b);
}

void	scena_rra_rb(int pos_a, int pos_b, t_list **a, t_list **b)
{
	int	i;
	int	size_a;

	i = -1;
	size_a = ft_lstsize(*a);
	if (pos_a >= size_a)
    	return ;
	while (++i < pos_b)
		rotate_b(b);
	i = -1;
	while (++i <  size_a - pos_a)
		re_rotate_a(a);
}

void	rotations_push_a(t_list **stack_a, t_list **stack_b)
{
	int	pos_a;
	int	pos_b;
	int	*costs;
	int	scena;

	while (*stack_b)
	{
		pos_b = 0;
		pos_a = set_pos_a_target(*stack_a, (*stack_b)->index);
		costs = cost_diff_scena(pos_a, pos_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		scena = cheapest_scena(costs);
		if (scena == 0)
			scena_rr(pos_a, pos_b, stack_a, stack_b);
		else if (scena == 1)
			scena_rrr(pos_a, pos_b, stack_a, stack_b);
		else if (scena == 2)
			scena_ra_rrb(pos_a, pos_b, stack_a, stack_b);
		else if (scena == 3)
			scena_rra_rb(pos_a, pos_b, stack_a, stack_b);
		push_a(stack_a, stack_b);
		free(costs);
	}
	while ((*stack_a)->index != 0)
	{
		if (find_index_pos(*stack_a, 0) > ft_lstsize(*stack_a) / 2)
			re_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}
