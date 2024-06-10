/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:33:46 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:47:09 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	null_case_right_s(t_flags *status, int **length)
{
	if (status->point == '.')
	{
		if (status->number >= 6)
		{
			**length += write_space(status->width - 6);
			**length += write(1, "(null)", 6);
		}
		else
			**length += write_space(status->width);
	}
	else
	{
		**length += write_space(status->width - 6);
		**length += write(1, "(null)", 6);
	}
}

void	justify_right_s(t_flags *status, t_data *lst, int *length)
{
	int	i;
	int	len_to_print;

	i = -1;
	if (lst->str == NULL)
	{
		null_case_right_s(status, &length);
		return ;
	}
	if (status->point == '.' && status->number < (int)ft_strlen(lst->str))
		len_to_print = status->number;
	else
		len_to_print = ft_strlen(lst->str);
	if (status->width > len_to_print)
		*length += write_space(status->width - len_to_print);
	while (++i < len_to_print)
		*length += ft_putchar((lst->str)[i]);
}

void	null_case_left_s(t_flags *status, int **length)
{
	if (status->point == '.')
	{
		if (status-> number >= 6)
		{
			**length += write(1, "(null)", 6);
			**length += write_space(status->width - 6);
		}
		else
			**length += write_space(status->width);
	}
	else
	{
		**length += write(1, "(null)", 6);
		**length += write_space(status->width - 6);
	}
}

void	justify_left_s(t_flags *status, char f, t_data *lst, int *length)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (lst->str == NULL)
	{
		null_case_left_s(status, &length);
		return ;
	}
	if (status->point == '.' && status->number < (int)ft_strlen(lst->str))
	{
		while (++i < status->number)
			len += ft_putchar((lst->str)[i]);
	}
	else
	{
		print_value_flags(f, lst);
		len += ft_strlen(lst->str);
	}
	if (len < status->width)
		*length += write_space(status->width - len);
	*length += len;
}

void	ft_print_s(t_flags *status, char f, t_data *list, int ****value)
{
	int	length;

	length = 0;
	if (status->minus == '-')
		justify_left_s(status, f, list, &length);
	else
		justify_right_s(status, list, &length);
	****value += length;
}
