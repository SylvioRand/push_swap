/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:29:05 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 11:37:46 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	justify_right_p(t_flags *status, t_data *lst, char f, int *len)
{
	int	nb_dgt;
	int	len_to_print;

	nb_dgt = nb_char_p(lst->nb_uint_ptr);
	if (lst->nb_uint_ptr == 0)
	{
		*len += write_space(status->width - 5);
		*len += write(1, "(nil)", 5);
		return ;
	}
	if (status->number < nb_dgt)
		status->number = nb_dgt;
	if (status->hashtag == '#')
		status->width += -2;
	if (status->number > nb_dgt + 2)
		len_to_print = status->number + 2;
	else
		len_to_print = nb_dgt + 2;
	if (status->width > len_to_print - 2)
		*len = write_space(status->width - len_to_print);
	*len += write(1, "0x", 2);
	if (status->number > nb_dgt + 2)
		*len += write_zero(status->number - nb_dgt);
	print_value_flags(f, lst);
	*len += nb_dgt;
}

void	justify_left_p(t_flags *status, t_data *list, char f, int *length)
{
	int	nb_dgt;
	int	len_to_print;

	nb_dgt = nb_char_p(list->nb_uint_ptr);
	if (list->nb_uint_ptr == 0)
	{
		*length += write(1, "(nil)", 5);
		*length += write_space(status->width - 5);
		return ;
	}
	*length += write(1, "0x", 2);
	if (status->number > nb_dgt)
		*length += write_zero(status->number - nb_dgt);
	print_value_flags(f, list);
	*length += nb_dgt;
	if (status->number > nb_dgt + 2)
		len_to_print = status->number + 2;
	else
		len_to_print = nb_dgt + 2;
	if (status->width > len_to_print)
		*length += write_space(status->width - len_to_print);
}

void	zero_flags_p(t_flags *status, t_data *lst, char f, int *len)
{
	int	nb_dgt;

	nb_dgt = nb_char_p(lst->nb_uint_ptr);
	if (lst->nb_uint_ptr == 0)
	{
		*len += write_space(status->width - 5);
		*len += write(1, "(nil)", 5);
		return ;
	}
	*len += write(1, "0x", 2);
	if (status->width > (*len + nb_dgt))
		*len += write_zero (status->width - (nb_dgt + 2));
	print_value_flags(f, lst);
	*len += nb_dgt;
}

void	ft_print_p(t_flags *status, char f, t_data *list, int ****value)
{
	int	length;

	length = 0;
	if (status->minus == '-')
		justify_left_p(status, list, f, &length);
	else if (status->zero == '0')
		zero_flags_p(status, list, f, &length);
	else
		justify_right_p(status, list, f, &length);
	****value += length;
}
