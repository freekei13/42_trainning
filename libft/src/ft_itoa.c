/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:07:33 by csamakka          #+#    #+#             */
/*   Updated: 2025/10/13 15:48:50 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*str;
	long int	n;

	n = nb;
	len = ft_intlen(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
