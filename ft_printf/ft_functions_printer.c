/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:34:10 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:47:39 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_value_flags(char f, t_data *list)
{
	if (f == 'c')
		ft_putchar(list->nb_int);
	if (f == 's')
		ft_putstr(list->str);
	if (f == 'p')
		ft_print_adress_bonus(list->nb_uint_ptr);
	if (f == 'd')
		ft_putnbr_i_bonus(ft_abs(list->nb_int), 0);
	if (f == 'i')
		ft_putnbr_i_bonus(ft_abs(list->nb_int), 0);
	if (f == 'u')
		ft_putnbr_u(list->nb_uint, 0);
	if (f == 'x')
		ft_putnbr_x_bonus(list->nb_uint, "0123456789abcdef");
	if (f == 'X')
		ft_putnbr_x_bonus(list->nb_uint, "0123456789ABCDEF");
	if (f == '%')
		ft_putchar('%');
}

int	write_zero(int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		ft_putchar('0');
	}
	return (i);
}

int	write_space(int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		ft_putchar(' ');
	}
	return (i);
}

void	write_sign(t_flags *status, t_data *lst, int *nb_dgt, int **len)
{
	if (lst->nb_int < 0)
		ft_putchar('-');
	if (status->plus == '+')
		**len += ft_putchar('+');
	if (status->space == ' ')
		**len += ft_putchar(' ');
	if (lst->nb_int < 0)
		*nb_dgt = *nb_dgt - 1;
}
