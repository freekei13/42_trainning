/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:54 by freekei           #+#    #+#             */
/*   Updated: 2025/10/20 15:35:26 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int  ft_print_char(int arg)
{
    write(1, &arg, 1);
    return (1);
}
int  ft_print_str(char *arg)
{
    int  i;
    
    i = 0;
    while (arg[i])
    {
        write(1, &arg[i], 1);
        i++;
    }
    return (i);
}

int ft_intlen(long nb)
{
	int i;

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

int ft_print_nbr(long nb)
{
    int     len;
    
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

int ft_hexlen(unsigned int nb)
{
    int i;
    
    i = 0;
    while (nb != 0)
    {
        nb = nb / 16;
        i++;
    }
    return (i);
}

int ft_print_hex(unsigned int arg, char c)
{
    char    *base_hex;
    char    *hex;
    int     i;
    
    if (c == 'X')
        base_hex = "0123456789ABCDEF";
    else
        base_hex = "0123456789abcdef";
    hex = malloc(ft_hexlen(arg) + 1);
    if (!hex)
        return (-1);
    i = 0;
    while (arg != 0)
    {
        hex[i] = base_hex[arg % 16];
        arg = arg / 16;
        i++;
    }
    hex[i] = 0;
    while (hex[i - 1])
    {
        write(1, &hex[i - 1], 1);
        i--;
    }
    free(hex);
    return (ft_hexlen(arg));
}

int ft_print_ptr(void *arg)
{
    unsigned int    *ptr;

    ptr = (unsigned int *)arg;
    return(0);
}

#include <stdio.h>
int main(void)
{
    char *test = "Kaito";
    ft_print_ptr(test);
}