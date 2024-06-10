/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:11:33 by srandria          #+#    #+#             */
/*   Updated: 2024/03/26 15:13:01 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_putnbr_u(unsigned int nb, int value)
{
	if ((int)nb >= 0 && nb < 10)
		value += ft_putchar(nb + 48);
	if (nb > 9)
	{
		value = ft_putnbr_u(nb / 10, value);
		value += ft_putchar(nb % 10 + 48);
	}
	return (value);
}
