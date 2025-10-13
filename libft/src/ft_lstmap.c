/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:31:56 by freekei           #+#    #+#             */
/*   Updated: 2025/10/14 00:49:31 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *new_obj;
    
    if (!lst || !*f || !del)
        return (NULL);
    new_lst = NULL;
    while (lst)
    {
        new_obj = ft_lstnew(f(lst->content));
        if (!new_obj)
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_obj);
        lst = lst->next;
    }
    return (new_lst);
}