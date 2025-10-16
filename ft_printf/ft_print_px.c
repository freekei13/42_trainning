/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:14:52 by freekei           #+#    #+#             */
/*   Updated: 2025/10/16 17:01:08 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

size_t  ft_print_hex(void *arg, size_t len)
{
    char            *hex_base;
    unsigned char   *a;
    size_t          i;
    char            *tmp;
    
    hex_base = "0123456789abcdef";
    a = (unsigned char *)arg;
    i = 0;
    while(a[i])
    {
        while (a[i] != 0)
        {
            a[i] = a[i] / 16;
            *tmp++ = hex_base[a[i] % 16];
        }
        i++;
    }
    tmp = 0;
    while (--tmp)
    {
        ft_putchar_fd(tmp, 1);
        len++;
    }
    return (len);
}