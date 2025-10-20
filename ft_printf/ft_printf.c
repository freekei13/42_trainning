/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:21:51 by freekei           #+#    #+#             */
/*   Updated: 2025/10/21 00:15:17 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arguments(va_list args, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (type == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		len += ft_print_nbr(va_arg(args, long));
	else if (type == 'u')
		len += ft_print_unbr(va_arg(args, long));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len_total;

	i = 0;
	len_total = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len_total += ft_arguments(args, format[i + 1]);
			i++;
		}
		else
			len_total += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len_total);
}
