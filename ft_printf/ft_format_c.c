/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:23:50 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:47:15 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	justify_right_c(t_flags *status, t_data *lst, int *length)
{
	if (status->width > 1)
		*length += write_space(status->width - 1);
	*length += ft_putchar(lst->nb_int);
}

void	justify_left_c(t_flags *status, t_data *lst, int *length)
{
	*length += ft_putchar(lst->nb_int);
	if (status->width > 1)
		*length += write_space(status->width - 1);
}

void	ft_print_c(t_flags *status, t_data *list, int ****value)
{
	int	length;

	length = 0;
	if (status->minus == '-')
		justify_left_c(status, list, &length);
	else
		justify_right_c(status, list, &length);
	****value += length;
}
