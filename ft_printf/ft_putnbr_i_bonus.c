/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_i_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:11:33 by srandria          #+#    #+#             */
/*   Updated: 2024/04/08 11:25:58 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_putnbr_i_bonus(int nb, int value)
{
	if (nb == -2147483648)
	{
		value = write(1, "2147483648", 10);
	}
	else if (nb >= 0 && nb < 10)
		value += ft_putchar(nb + 48);
	else if (nb > 9)
	{
		value = ft_putnbr_i(nb / 10, value);
		value += ft_putchar(nb % 10 + 48);
	}
	else if (nb < 0)
	{
		value += write(1, "-", 1);
		value = ft_putnbr_i(-nb, value);
	}
	return (value);
}
