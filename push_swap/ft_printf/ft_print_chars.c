/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:27:24 by freekei           #+#    #+#             */
/*   Updated: 2025/10/21 12:20:01 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_char(int arg)
{
	write(1, &arg, 1);
	return (1);
}

int	ft_print_str(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (arg[i])
	{
		ft_putchar(arg[i]);
		i++;
	}
	return (i);
}
