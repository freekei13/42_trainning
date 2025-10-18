/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:54 by freekei           #+#    #+#             */
/*   Updated: 2025/10/18 14:31:48 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
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
        ft_putchar_fd(1, arg[i], 1);
        i++;
    return (i);
}
