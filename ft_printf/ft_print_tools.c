/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:54 by freekei           #+#    #+#             */
/*   Updated: 2025/10/20 20:42:38 by freekei          ###   ########.fr       */
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

int ft_hexlen(unsigned long long nb)
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

int ft_print_hex(unsigned long long arg, char c)
{
    char    *base_hex;
    char    hex[16];
    int     i;
    int     len;
    
    if (c == 'X')
        base_hex = "0123456789ABCDEF";
    else
        base_hex = "0123456789abcdef";
    i = 0;
    len = ft_hexlen(arg);
    while (arg != 0)
    {
        hex[i] = base_hex[arg % 16];
        arg = arg / 16;
        i++;
    }
    while (hex[i - 1])
    {
        write(1, &hex[i - 1], 1);
        i--;
    }
    return (len);
}

int ft_print_ptr(void *arg)
{
    unsigned long long    ptr;
    int                   len;  
    
    len = 0;
    ptr = (unsigned long long)arg;
    len += ft_print_str("0x");
    len += ft_print_hex(ptr, 'x');
    
    return(len);
}

#include <stdio.h>
int main(void)
{
    char *test = "Kaito";
    int len = ft_print_ptr(test);
    ft_putchar('\n');
    printf("%p\n", test);
    ft_print_nbr(len);
    ft_putchar('\n');
}