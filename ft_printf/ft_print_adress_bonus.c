/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:34:53 by srandria          #+#    #+#             */
/*   Updated: 2024/04/10 21:34:57 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_size(char *base)
{
	int	count;

	count = -1;
	while (base[++count])
	{
	}
	return (count);
}

int	ft_dec_to_b(long unsigned int decimal, int *base_c, int base_s)
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

void	ft_write_base(char *base, int *base_code, int j)
{
	char	c;

	while (j >= 0)
	{
		c = base[base_code[j--]];
		write(1, &c, 1);
	}
}

void	ft_putnbr_b_ptr(long unsigned int nbr, char *base)
{
	long unsigned int	base_size;
	int					j;
	int					base_code[50];

	base_size = ft_base_size(base);
	j = ft_dec_to_b(nbr, base_code, base_size);
	ft_write_base(base, base_code, j);
}

void	ft_print_adress_bonus(long unsigned int ptr)
{
	ft_putnbr_b_ptr(ptr, "0123456789abcdef");
}
