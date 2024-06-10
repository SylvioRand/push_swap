/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_initial_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:34:18 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:35:02 by srandria         ###   ########.fr       */
/*                                                                          */
/* ************************************************************************** */

int	nb_digit(long value, char f)
{
	int	length;

	length = 0;
	if (value == -2147483648)
		return (11);
	if (value == 4294967295)
		return (10);
	if (f == 'd' || f == 'i' || f == 'u')
	{
		if (value == 0)
			return (1);
		if (value < 0)
		{
			length++;
			value *= -1;
		}
		while (value > 0)
		{
			length++;
			value /= 10;
		}
		return (length);
	}
	return (0);
}

int	nb_char_x(unsigned int value)
{
	int	i;
	int	one;

	i = -1;
	one = 1;
	if (value == 0)
		return (one);
	while (value != 0)
	{
		++i;
		value /= 16;
	}
	return (i + 1);
}

int	nb_char_p(unsigned long int value)
{
	int	i;

	i = -1;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		++i;
		value /= 16;
	}
	return (i + 1);
}
