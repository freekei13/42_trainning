#include "push_swap.h"

void	push_b_all_except_lis(int size, int *lis, t_list **stack_a, t_list **stack_b)
{
	int i;
	int exist;

	while (size--)
	{
		i = 0;
		exist = 0;
		while (lis[i] != -1)
		{
			if ((*stack_a)->index == lis[i++])
				exist++;
		}
		if (exist != 0)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
	}
}

int	set_pos_a_target(t_list *stack_a, int index_b)
{
	int		pos;
	int		min;
	t_list	*tmp;

	pos = 0;
	min = find_min_index(stack_a);
	tmp = stack_a;
	if (index_b < min || index_b > find_max_index(stack_a))
	{
		while (tmp->index != min)
		{
			tmp = tmp->next;
			pos++;
		}
		return (pos);
	}
	while (tmp->next)
	{
		if(index_b > tmp->index && index_b < tmp->next->index)
			return (pos + 1);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}
void	scenario_assign(int *scen1, int *scen2, int *scen3, int *scen4,)
{
		ra_rb = cost_ra_rb(pos_a, pos_b);
		rra_rrb = cost_rra_rrb(pos_a, pos_b, size_a, size_b);
		ra_rrb = cost_ra_rrb(pos_a, pos_b, size_b);
		rra_rb = cost_rra_rb(pos_a, pos_b, size_a);
}

int	set_best_pos_b(t_list *stack_a, t_list *stack_b)
{
	int		best_b;
	int		pos_a;
	int 	pos_b;
	int		size_a;
	int 	size_b;
	int 	ra_rb;
	int		rra_rrb;
	int 	ra_rrb;
	int 	rra_rb;
	int		cheapest;
	int		prev_cheapest;
	t_list *tmp;

	pos_b = 0;
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	best_b = pos_b;
	prev_cheapest = INT_MAX;
	tmp = stack_b;
	while (tmp)
	{
		pos_a = set_pos_a_target(stack_a, tmp->index);
		
		cheapest = cheapest_cost(ra_rb, rra_rrb, ra_rrb, rra_rb);
		if (prev_cheapest > cheapest)
		{
			best_b = pos_b;
			prev_cheapest = cheapest;
		}
		pos_b++;
		tmp = tmp->next;
	}
	return (best_b);
}
