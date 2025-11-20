#include "push_swap.h"

t_list	parse_inputs(char **args)
{
	t_list	stack_a;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!stack_a)
			stack_a = ft_lstnew(ft_atoi(args[i]));
		else
			stack_a = ft_lstadd_back(ft_atoi(args[i]));
		i++;
	}
	return (stack_a);
}