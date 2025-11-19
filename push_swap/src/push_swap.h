/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:20 by csamakka          #+#    #+#             */
/*   Updated: 2025/11/19 15:16:09 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PUSH_SWAP_H
# define	PUSH_SWAP_H
# include	<limits.h>
# include	"../libft/libft.h"
# include	"../ft_printf/ft_printf.h"

char	**input_check(int ac, char *av[]);
int		error_check(char **inputs);
int		digit_check(char **inputs);
int		repeat_check(char **inputs);
int		int_minmax_check(char **inputs);
#endif