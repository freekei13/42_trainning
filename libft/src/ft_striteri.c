/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:06:01 by freekei           #+#    #+#             */
/*   Updated: 2025/10/13 16:13:15 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int    i;
    
    i = 0;
    while (s[i])
    {
        (*f)(i, &s[i]);
        i++;
    }
}