/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:35:47 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:31:05 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	print_value(char f, va_list arg, int **value)
{
	if (f == 'c')
		**value += ft_putchar(va_arg(arg, int));
	if (f == 's')
		**value += ft_putstr(va_arg(arg, char *));
	if (f == 'p')
		ft_print_adress(va_arg(arg, unsigned long), &value);
	if (f == 'd')
		**value += ft_putnbr_i(va_arg(arg, int), 0);
	if (f == 'i')
		**value += ft_putnbr_i(va_arg(arg, int), 0);
	if (f == 'u')
		**value += ft_putnbr_u(va_arg(arg, unsigned int), 0);
	if (f == 'x')
		ft_putnbr_x(va_arg(arg, int), "0123456789abcdef", &value);
	if (f == 'X')
		ft_putnbr_x(va_arg(arg, int), "0123456789ABCDEF", &value);
	if (f == '%')
		**value += ft_putchar('%');
}
