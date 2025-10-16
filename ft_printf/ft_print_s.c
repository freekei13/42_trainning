/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:54 by freekei           #+#    #+#             */
/*   Updated: 2025/10/16 16:28:02 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

size_t  ft_print_str(char *arg, size_t len)
{
    size_t  i;
    
    i = 0;
    while (arg[i++])
        ft_putchar_fd(1, arg[i], 1);
    return (len + i);
}
