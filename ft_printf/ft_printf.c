/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:21:51 by freekei           #+#    #+#             */
/*   Updated: 2025/10/20 21:31:31 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int ft_arguments(va_list args, char type)
{
    int len;

    len = 0;
    if (type == 'c')
        len += ft_print_char(va_arg(args, int));
    else if (type == 's')
        len += ft_print_str(va_arg(args, char *));
    else if (type == 'p')
        len += ft_print_ptr(va_arg(args, void *));
    else if (type == 'd' || type == 'i')
        len += ft_print_nbr(va_arg(args, long));
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     len_total; //every print: len_total = len_total + printed len.
    
    i = 0;
    len_total = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            len_total += ft_arguments(args, format[i + 1]);
                //print pointer hex base 16
                //print dec base 10
                //print int base 10 (use ft_itoa)
                //print unsigned dec base 10
                //print a number hex base 16
                //print % sign
        }
        else
        {
            write(1, &format[i], 1);
            len_total++;
        }
        i++;
    }
    va_end(args);
    return  (len_total);
}
