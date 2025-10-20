/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:58:04 by freekei           #+#    #+#             */
/*   Updated: 2025/10/21 00:21:57 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*str;
	int		nb;
	int		unb;
	char	c;

	str = "Hello";
	nb = 42;
	unb = 35;
	c = 75;
	ft_printf("%s\n%i\n%c\n%p\n%u\n", str, nb, c, &c, unb);
}
