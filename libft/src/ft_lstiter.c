/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:23:45 by freekei           #+#    #+#             */
/*   Updated: 2025/10/14 00:31:05 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *tmp;
    
    tmp = lst;
    while (tmp)
    {
        f(tmp->content);
        tmp = tmp->next;
    }
}