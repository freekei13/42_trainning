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

int		*parse_list(t_list *args)
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
	tmp[i] = 0;
	return (tmp);
}

void	buble_sort(int *args, int counter)
{
	int	nb_tmp;
	int	i;
	int	*tmp;

	tmp = args;
	while (counter > 0)
	{
		i = 0;
		while (tmp[i] && tmp[i + 1])
		{
			if (tmp[i] > tmp[i + 1])
			{
				nb_tmp = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = nb_tmp;
			}
			i++;
		}
		counter--;
	}
	args = tmp;
}

void	index_assign(t_list *args)
{
	int		*tmp;
	int		i;
	t_list	*head;

	head = args;
	i = ft_lstsize(args);
	tmp = parse_list(args);
	buble_sort(tmp, i);
	i = 0;
	while (tmp[i])
	{
		args = head;
		while (args)
		{
			if (args->content == tmp[i])
				args->index = i;
			args = args->next;
		}
		i++;
	}
	free(tmp);
	tmp = NULL;
}
