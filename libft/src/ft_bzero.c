/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:01:15 by csamakka          #+#    #+#             */
/*   Updated: 2025/07/24 23:21:17 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *) str;
	while (n--)
		*s++ = 0;
}
