/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:34:00 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:47:07 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	justify_right_x(t_flags *status, t_data *lst, char f, int *len)
{
	int	nb_dgt;

	nb_dgt = nb_char_x(lst->nb_uint);
	if (status->hashtag == '#')
		status->width += -2;
	if (status->number > nb_dgt)
		*len += write_space(status->width - status->number);
	else
		*len += write_space(status->width - nb_dgt);
	if (f == 'X' && status->hashtag == '#' && lst->nb_uint != 0)
		*len += write (1, "0X", 2);
	if (f == 'x' && status->hashtag == '#' && lst->nb_uint != 0)
		*len += write (1, "0x", 2);
	if (status->plus == '+')
		*len += ft_putchar('+');
	if (status->space == ' ')
		*len += ft_putchar(' ');
	if (status->number > nb_dgt)
		*len += write_zero(status->number - nb_dgt);
	print_condition_u(status, lst, f, &len);
}

void	justify_left_x(t_flags *status, t_data *list, char f, int *length)
{
	int	s_number;
	int	nb_dgt;

	s_number = status->number;
	nb_dgt = nb_char_x(list->nb_uint);
	if (f == 'X' && status->hashtag == '#' && list->nb_uint != 0)
		*length += write(1, "0X", 2);
	if (f == 'x' && status->hashtag == '#' && list->nb_uint != 0)
		*length += write(1, "0x", 2);
	if (status->space == ' ')
		*length += ft_putchar(status->space);
	if (status->plus == '+')
		*length += ft_putchar(status->plus);
	if (s_number > (*length + nb_dgt))
		*length += write_zero(s_number - (*length + nb_dgt));
	print_condition_u(status, list, f, &length);
	if (status->number > nb_dgt)
		*length += write_space(status->width - status->number);
	else
		*length += write_space(status->width - nb_dgt);
}

void	zero_flags_x(t_flags *status, t_data *lst, char f, int *len)
{
	int	nb_dgt;

	nb_dgt = nb_char_x(lst->nb_uint);
	if (status->width > (*len + nb_dgt))
		*len += write_zero(status->width - (*len + nb_dgt));
	print_value_flags(f, lst);
	*len += nb_dgt;
}

void	ft_print_x(t_flags *status, char f, t_data *list, int ****value)
{
	int	length;

	length = 0;
	if (status->minus == '-')
		justify_left_x(status, list, f, &length);
	else if (status->zero == '0')
		zero_flags_x(status, list, f, &length);
	else
	{
		justify_right_x(status, list, f, &length);
	}
	****value += length;
}
