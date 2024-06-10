/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:48:03 by srandria          #+#    #+#             */
/*   Updated: 2024/04/12 12:30:44 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	format_print(t_flags *status, char f, t_data *list, int ***value)
{
	if (f == 'd' || f == 'u' || f == 'i')
		ft_print_diu(status, list, f, &value);
	if (f == 'c')
		ft_print_c(status, list, &value);
	if (f == 's')
		ft_print_s(status, f, list, &value);
	if (f == 'X' || f == 'x')
		ft_print_x(status, f, list, &value);
	if (f == 'p')
		ft_print_p(status, f, list, &value);
}

void	find_flags(char *flags, t_flags *status, char f, int *i)
{
	int	i_f;

	i_f = 0;
	while (flags[i_f] == '-' || flags[i_f] == '+' || flags[i_f] == ' '
		|| flags[i_f] == '#' || flags[i_f] == '0')
	{
		if (flags[i_f] == '-')
			status->minus = flags[i_f];
		if (flags[i_f] == '+' && ((f == 'd') || (f == 'i')))
			status->plus = flags[i_f];
		if (flags[i_f] == ' ' && ((f == 'd') || (f == 'i')))
			status->space = flags[i_f];
		if (flags[i_f] == '0' && ((f == 'd') || (f == 'i') || (f == 'u')
				|| (f == 'x') || (f == 'X') || (f == 'p')))
			status->zero = flags[i_f];
		if (flags[i_f] == '#' && ((f == 'x') || (f == 'X')))
			status->hashtag = flags[i_f];
		i_f++;
	}
	*i = i_f;
}

void	read_flags(char *flags, char f, t_data *list, int **value)
{
	int		i;
	t_flags	*status;

	status = malloc(sizeof(t_flags));
	init_status(status);
	i = 0;
	find_flags(flags, status, f, &i);
	if (status->minus == '-')
		status->zero = 0;
	while (flags[i] >= '0' && flags[i] <= '9')
		status->width = status->width * 10 + (flags[i++] - 48);
	if (flags[i] == '.')
	{
		status->point = flags[i++];
		status->zero = 0;
	}
	while (flags[i] >= '0' && flags[i] <= '9')
		status->number = status->number * 10 + (flags[i++] - 48);
	format_print(status, f, list, &value);
	free(status);
}

void	traitement(char *flags, char f, va_list arg_ptr, int *value)
{
	t_data	*list;

	list = malloc(sizeof(t_data));
	init_list(list);
	if (ft_strlen(flags) == 0)
		print_value(f, arg_ptr, &value);
	else if (f == 'd' || f == 'i' || f == 'c')
		list->nb_int = va_arg(arg_ptr, int);
	else if (f == 'u' || f == 'x' || f == 'X')
		list->nb_uint = va_arg(arg_ptr, unsigned int);
	else if (f == 'p')
		list->nb_uint_ptr = va_arg(arg_ptr, unsigned long);
	else if (f == 's')
		list->str = va_arg(arg_ptr, char *);
	else if (f == '%')
		*value += write(1, "%", 1);
	if (ft_strlen(flags) != 0)
		read_flags(flags, f, list, &value);
	free(list);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		value;
	char	*flags;
	char	*fo_cp;
	int		format_p;

	value = 0;
	va_start (arg_ptr, format);
	fo_cp = (char *)format;
	while (*fo_cp)
	{
		if (*fo_cp == '%')
		{
			format_p = format_pos(fo_cp + 1);
			flags = malloc(sizeof(char) * (format_p + 1));
			fill_flags(fo_cp, flags, format_p);
			traitement(flags, fo_cp[format_p + 1], arg_ptr, &value);
			fo_cp = fo_cp + format_p + 1;
			free(flags);
		}
		else
			value += ft_putchar(*fo_cp);
		fo_cp++;
	}
	return (va_end(arg_ptr), value);
}
