/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:14:59 by srandria          #+#    #+#             */
/*   Updated: 2024/04/05 14:25:06 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	ft_base_size(char *base)
{
	int	count;

	count = -1;
	while (base[++count])
	{
	}
	return (count);
}

static int	ft_dec_to_b(unsigned int decimal, int *base_c, int base_s)
{
	int	j;

	j = -1;
	while (decimal != 0)
	{
		base_c[++j] = decimal % base_s;
		decimal /= base_s;
	}
	return (j);
}

static void	ft_write_base(char *base, int *base_code, int j, int ****value)
{
	char	c;

	while (j >= 0)
	{
		c = base[base_code[j--]];
		****value += write(1, &c, 1);
	}
}

void	ft_putnbr_x(unsigned int nbr, char *base, int ***value)
{
	long unsigned int	base_size;
	int					j;
	int					base_code[50];

	if (nbr == 0)
		***value += write(1, "0", 1);
	base_size = ft_base_size(base);
	j = ft_dec_to_b(nbr, base_code, base_size);
	ft_write_base(base, base_code, j, &value);
}
