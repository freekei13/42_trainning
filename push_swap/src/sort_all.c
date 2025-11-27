/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:27:07 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/27 01:01:40 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_len_prev(int *a, int *len, int *prev, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (a[j] < a[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*set_lis(t_list *stack_a)
{
	int	*a;
	int	*len;
	int	*prev;
	int	i;
	int	j;
	int	size;

	int max_len;
	int end;
	
	int *lis;
	
	size = ft_lstsize(stack_a);
	a = parse_index(stack_a);
	len = malloc(sizeof(int) * size);
	prev = malloc(sizeof(int) * size);
	if (!len || !prev || !a)
	{
		free(len);
		free(prev);
		free(a);
		return (NULL);
	}
	set_len_prev(a, len, prev, size);
	max_len = 0;
	end = 0;
	i = 0;
	while (i < size)
	{
		if (len[i] > max_len)
		{
			max_len = len[i];
			end = i;
		}
		i++;
	}
	lis = malloc(sizeof(int) * (max_len + 1));
	i = max_len - 1;
	j = end;
	while (j != -1)
	{
		lis[i] = a[j];
		i--;
		j = prev[j];
	}
	lis[max_len] = -1;
	free(a);
	free(len);
	free(prev);
	return (lis);
}

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	int	*lis;
	int i;
	int	size;
	int exist;
	
	lis = set_lis(*stack_a);
	size = ft_lstsize(*stack_a);
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
	free(lis);
}
