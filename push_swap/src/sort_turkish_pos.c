#include "push_swap.h"

void	push_b_all_except_lis(int size, int *lis, t_list **stack_a, t_list **stack_b)
{
	int i;
	int exist;

	while (size > 0 && *stack_a)
	{
		i = 0;
		exist = 0;
		while (lis[i] != -1)
		{
			if ((*stack_a)->index == lis[i])
				exist++;
			i++;
		}
		if (exist != 0)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
		size--;
	}
}

int find_pos_b_index(int pos_b, t_list *stack_b)
{
    int i = 0;

    while (stack_b && i < pos_b)
    {
        stack_b = stack_b->next;
        i++;
    }
    if (!stack_b)
        return (-1);
    return (stack_b->index);
}

int	set_pos_a_target(t_list *stack_a, int index_b)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	if (index_b == -1)
		return (0);
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
		if(index_b > tmp->index && index_b < tmp->next->index)
			return (pos + 1);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

int set_best_pos_b(t_list *stack_a, t_list *stack_b)
{
    int best_b = 0;
    int prev_cheapest = INT_MAX;
    int pos_b = 0;

    t_list *tmp = stack_b;

    while (tmp)
    {
        int index_b = tmp->index;
        int pos_a = set_pos_a_target(stack_a, index_b);
        int size_a = ft_lstsize(stack_a);
        int size_b = ft_lstsize(stack_b);
        int *costs = cost_diff_scena(pos_a, pos_b, size_a, size_b);
        if (!costs)
            return (-1);
        int cheap = cheapest_cost(costs);
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
