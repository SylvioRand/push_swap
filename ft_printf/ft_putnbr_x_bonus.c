/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:57:06 by srandria          #+#    #+#             */
/*   Updated: 2024/04/05 16:51:03 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	ft_write_base(char *base, int *base_code, int j)
{
	char	c;

	while (j >= 0)
	{
		c = base[base_code[j--]];
		write(1, &c, 1);
	}
}

void	ft_putnbr_x_bonus(unsigned int nbr, char *base)
{
	long unsigned int	base_size;
	int					j;
	int					base_code[50];

	if (nbr == 0)
		write(1, "0", 1);
	base_size = ft_base_size(base);
	j = ft_dec_to_b(nbr, base_code, base_size);
	ft_write_base(base, base_code, j);
}
