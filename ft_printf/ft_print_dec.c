/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:30:05 by freekei           #+#    #+#             */
/*   Updated: 2025/10/21 00:20:15 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_print_nbr(long nb)
{
	int	len;

	len = ft_intlen(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_print_nbr(nb);
	}
	else if (nb > 9)
	{
		ft_print_nbr(nb / 10);
		ft_print_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}

int	ft_print_unbr(unsigned long nb)
{
	int	len;

	len = ft_intlen(nb);
	if (nb > 9)
	{
		ft_print_nbr(nb / 10);
		ft_print_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
