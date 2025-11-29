/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turkish_lis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:27:07 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/29 02:16:46 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lis_assem(int *a, int *prev, int max_len, int end)
{
	int *lis;
	int	i;
	int	j;
	
	lis = malloc(sizeof(int) * (max_len + 1));
	if (!lis)
		return (NULL);
	i = max_len - 1;
	j = end;
	while (j != -1)
	{
		lis[i] = a[j];
		i--;
		j = prev[j];
	}
	lis[max_len] = -1;
	return (lis);
}

void	set_lis_maxlen_end(int *max_len, int *end, int size, int *len)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		if (len[i] > *max_len)
		{
			*max_len = len[i];
			*end = i;
		}
		i++;
	}
}
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
	int	size;
	int max_len;
	int end;
	int *lis;
	
	size = ft_lstsize(stack_a);
	a = parse_index(stack_a);
	len = malloc(sizeof(int) * size);
	prev = malloc(sizeof(int) * size);
	if (!len || !prev || !a)
		return (free(len), free(prev), free(a), NULL);
	set_len_prev(a, len, prev, size);
	max_len = 0;
	end = 0;
	set_lis_maxlen_end(&max_len, &end, size, len);
	lis = lis_assem(a, prev, max_len, end);
	if (!lis)
		return (free(len), free(prev), free(a), NULL);
	return (free(len), free(prev), free(a), lis);
}

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	int	*lis;
	int	size;
	
	lis = set_lis(*stack_a);
	if (!lis)
		return ;
	size = ft_lstsize(*stack_a);
	push_b_all_except_lis(size, lis, stack_a, stack_b);
	rotations_push_a(stack_a, stack_b);
	free(lis);
}
