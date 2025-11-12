/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freekei <freekei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:42:33 by freekei           #+#    #+#             */
/*   Updated: 2025/10/21 00:14:35 by freekei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_print_char(int arg);
int		ft_print_str(char *arg);
int		ft_print_nbr(long nb);
int		ft_print_unbr(unsigned long nb);
int		ft_print_hex(unsigned long long arg, char c);
int		ft_print_ptr(void *arg);

#endif