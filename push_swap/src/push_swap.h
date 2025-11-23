/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:20 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/23 22:15:42 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PUSH_SWAP_H
# define	PUSH_SWAP_H
# include	<limits.h>
# include	"../libft/libft.h"
# include	"../ft_printf/ft_printf.h"

void	push_swap(t_list **stack_a, t_list **stack_b);

char	**input_check(int ac, char *av[]);
void	free_lst(t_list **lst);
int		error_check(char **inputs);
int		digit_check(char **inputs);
int		repeat_check(char **inputs);
int		int_minmax_check(char **inputs);
t_list	*parse_inputs(char **args);
void	index_assign(t_list *args);

void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	sa_sb(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list	**stack_a);
void	rotate_b(t_list	**stack_b);
void	ra_rb(t_list **stack_a, t_list **stack_b);
void	re_rotate_a(t_list **stack_a);
void	re_rotate_b(t_list **stack_b);
void	rra_rrb(t_list **stack_a, t_list **stack_b);

void	three_args_sort(t_list **stack_a, t_list **stack_b);

//For testing only
void	print_stacks(t_list *a, t_list *b);
#endif