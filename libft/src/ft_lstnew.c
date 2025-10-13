/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:53:17 by freekei           #+#    #+#             */
/*   Updated: 2025/10/13 23:14:25 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *new_list;
    
    new_list = malloc(sizeof(t_list));
    if (!new_list)
        return (NULL);
    new_list->content = content;
    new_list->next = NULL;
    return (new_list);
}