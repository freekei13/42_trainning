/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:14:46 by csamakka          #+#    #+#             */
/*   Updated: 2025/07/24 01:16:15 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*str_dup;

	if (!str)
		return (NULL);
	str_dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str_dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_dup[i] = str[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}
