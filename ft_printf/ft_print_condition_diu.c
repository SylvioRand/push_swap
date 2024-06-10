/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_condition_diu.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:35:29 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:47:04 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	len_for_pos_value(t_flags *status, int nb_dgt, int *len_to_print)
{
	if (status->number != 0 && status->number > nb_dgt)
		*len_to_print = status->number;
	else
		*len_to_print = nb_dgt;
	if (status->plus == '+' || status->plus == ' ')
		*len_to_print += 1;
}

int	def_len_to_print(t_flags *status, int nb_dgt, t_data *lst, char f)
{
	int	len_to_print;

	len_to_print = 0;
	if ((f == 'd' || f == 'i') && lst->nb_int < 0)
	{
		if (status->number > nb_dgt)
			len_to_print = status->number + 1;
		else
		{
			if (status->minus == '-')
			{
				if (status->number > nb_dgt - 1)
					len_to_print = nb_dgt + 1;
				else
					len_to_print = nb_dgt;
			}
			else if (status->number >= nb_dgt)
				(status->width)--;
			if (status->minus != '-')
				len_to_print = nb_dgt;
		}
	}
	else
		len_for_pos_value(status, nb_dgt, &len_to_print);
	return (len_to_print);
}

void	print_condition_di(t_flags *status, t_data *lst, char f, int **len)
{
	int	nb_dgt;

	nb_dgt = nb_digit(lst->nb_int, f);
	if (status->point == '.' && status->number == 0 && lst->nb_int == 0)
	{
		if (status->width > 0)
			**len += ft_putchar(' ');
		return ;
	}
	print_value_flags(f, lst);
	**len += nb_dgt;
}

void	print_condition_u(t_flags *status, t_data *lst, char f, int **len)
{
	int	nb_dgt;

	if (f == 'u')
		nb_dgt = nb_digit(lst->nb_uint, 'u');
	if (f == 'x' || f == 'X')
		nb_dgt = nb_char_x(lst->nb_uint);
	if (status->point == '.' && status->number == 0 && lst->nb_uint == 0)
	{
		if (status->width > 0)
			**len += ft_putchar(' ');
		return ;
	}
	print_value_flags(f, lst);
	**len += nb_dgt;
}
