/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:59:11 by csamakka          #+#    #+#             */
/*   Updated: 2025/07/24 17:28:04 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <limits.h>

int	str_convert(int sign, long res, const char *str)
{
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && res > (long)INT_MAX + 1))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		str++;
	}
	return ((int)res);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = str_convert(sign, res, str);
	return ((int)res * sign);
}
