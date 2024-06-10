/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:28:50 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 11:09:48 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	justify_left_du(t_flags *status, t_data *lst, char f, int *len)
{
	int	nb_dgt;
	int	len_to_print;

	nb_dgt = 0;
	len_to_print = 0;
	if (f == 'd' || f == 'i')
		nb_dgt = nb_digit(lst->nb_int, f);
	if (f == 'u')
		nb_dgt = nb_digit(lst->nb_uint, f);
	len_to_print = def_len_to_print(status, nb_dgt, lst, f);
	write_sign(status, lst, &nb_dgt, &len);
	if (status->number > nb_dgt)
		*len += write_zero(status->number - nb_dgt);
	if (f == 'i' || f == 'd')
		print_condition_di(status, lst, f, &len);
	if (f == 'u')
		print_condition_u(status, lst, f, &len);
	if (status->space == ' ')
		len_to_print++;
	if (status->width > len_to_print)
		*len += write_space(status->width - len_to_print);
}

void	justify_right_du(t_flags *status, t_data *lst, char f, int *len)
{
	int	nb_dgt;
	int	len_to_print;

	len_to_print = 0;
	if (f == 'd' || f == 'i')
		nb_dgt = nb_digit(lst->nb_int, f);
	if (f == 'u')
		nb_dgt = nb_digit(lst->nb_uint, f);
	len_to_print = def_len_to_print(status, nb_dgt, lst, f);
	if (status->width > len_to_print)
		*len = write_space(status->width - len_to_print);
	write_sign(status, lst, &nb_dgt, &len);
	if (status->number > nb_dgt)
		*len += write_zero(status->number - nb_dgt);
	if (f == 'i' || f == 'd')
		print_condition_di(status, lst, f, &len);
	if (f == 'u')
		print_condition_u(status, lst, f, &len);
}

void	zero_flags_diu(t_flags *status, t_data *lst, char f, int *len)
{
	int	nb_dgt;

	if (f == 'd' || f == 'i')
		nb_dgt = nb_digit(lst->nb_int, f);
	else if (f == 'u')
		nb_dgt = nb_digit(lst->nb_uint, f);
	write_sign(status, lst, &nb_dgt, &len);
	if (lst->nb_int < 0)
	{
		(status->width)--;
		*len += 1;
	}
	if (status->width > nb_dgt)
		*len += write_zero(status->width - nb_dgt);
	print_value_flags(f, lst);
	*len += nb_dgt;
}

void	ft_print_diu(t_flags *status, t_data *list, char f, int ****value)
{
	int	length;

	length = 0;
	if (list->nb_int < 0)
		status->space = 0;
	if (status->plus == '+')
	{
		if (list->nb_int < 0)
			status->plus = 0;
	}
	if (status->minus == '-')
		justify_left_du(status, list, f, &length);
	else if (status->zero == '0')
	{
		if (list->nb_int < 0)
			status->space = 0;
		zero_flags_diu(status, list, f, &length);
	}
	else
		justify_right_du(status, list, f, &length);
	****value += length;
}
