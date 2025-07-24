/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:08:36 by csamakka          #+#    #+#             */
/*   Updated: 2025/07/25 00:31:32 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		ch;

	s = (unsigned char *)str;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*s == ch)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
