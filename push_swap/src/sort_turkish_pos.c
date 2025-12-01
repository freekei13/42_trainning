#include "push_swap.h"

int	find_pos_b_index(int pos_b, t_list *stack_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_b;
	while (tmp && i < pos_b)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->index);
}

int	set_pos_a_target(t_list *stack_a, int index_b)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = stack_a;
	if (index_b < find_min_index(stack_a) || index_b > find_max_index(stack_a))
	{
		while (tmp->index != find_min_index(stack_a))
		{
			tmp = tmp->next;
			pos++;
		}
		return (pos);
	}
	while (tmp->next)
	{
		if (index_b > tmp->index && index_b < tmp->next->index)
			return (pos + 1);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

int	set_best_pos_b(t_list *stack_a, t_list *stack_b)
{
	int		best_b;
	int		pos_a;
	int		pos_b;
	int		*costs;
	int		cheap;
	int		prev_cheapest;
	t_list	*tmp;

	pos_b = 0;
	tmp = stack_b;
	prev_cheapest = INT_MAX;
	while (tmp)
	{
		pos_a = set_pos_a_target(stack_a, tmp->index);
		costs = cost_diff_scena(pos_a, pos_b,
				ft_lstsize(stack_a), ft_lstsize(stack_b));
		if (!costs)
			return (-1);
		cheap = cheapest_cost(costs);
		free(costs);
		if (cheap < prev_cheapest)
		{
			prev_cheapest = cheap;
			best_b = pos_b;
		}
		pos_b++;
		tmp = tmp->next;
	}
	return (best_b);
}
