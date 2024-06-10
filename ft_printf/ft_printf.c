/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:48:03 by srandria          #+#    #+#             */
/*   Updated: 2024/04/10 21:02:30 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_if_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'c' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

void	traitement(char *flags, char f, va_list arg_ptr, int *value)
{
	free(flags);
	print_value(f, arg_ptr, &value);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		value;

	value = 0;
	va_start (arg_ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			while (ft_check_if_specifier(*(++format)) == 1)
			{
			}
			traitement(NULL, *(format), arg_ptr, &value);
		}
		else
			value += ft_putchar(*format);
		format++;
	}
	return (value);
}
