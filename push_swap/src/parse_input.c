#include "push_swap.h"

t_list	*parse_inputs(char **args)
{
	t_list	*stack_a;
	int		nb;
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(nb));
		i++;
	}
	return (stack_a);
}

int	*index_assign(t_list *args)
{
	int	*tmp;
	int	i;

	tmp = malloc((ft_lstsize(args) + 1) * sizeof(int));
	if (!tmp)
		return (NULL);
	i = 0;
	while (args)
	{
		tmp[i] = args->content;
		i++;
		args = args->next;
	}
	return (tmp);
}