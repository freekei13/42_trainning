/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:52:46 by freekei           #+#    #+#             */
/*   Updated: 2025/10/13 16:02:06 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t          s_len;
    unsigned int    i;
    char            *str;
    
    s_len = ft_strlen(s);
    str = malloc(sizeof(char) * s_len + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (i < s_len)
    {
        str[i] = (*f)(i, s[i]);
        i++;
    }
    str[i] = 0;
    return (str);
}