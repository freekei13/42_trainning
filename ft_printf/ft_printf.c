/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:21:51 by freekei           #+#    #+#             */
/*   Updated: 2025/10/16 16:06:57 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    size_t  i;
    size_t  len_total; //every print: len_total = len_total + printed len.
    
    i = 0;
    len_total = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            //if for all type : ft_print will print that var type and count len printed
                //print a char
                //print a string
                //print pointer hex base 16
                //print dec base 10
                //print int base 10 (use ft_itoa)
                //print unsigned dec base 10
                //print a number hex base 16
                //print % sign
        }
        else
            //putchar(format[i])
        i++;
    }
    va_end(args);
    return  (len_total);
}
