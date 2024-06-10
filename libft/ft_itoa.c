/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:38:45 by srandria          #+#    #+#             */
/*   Updated: 2024/03/01 18:34:59 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_s(char *s, int n, int end, int start)
{
	int	buffer;
	int	end_cp;

	buffer = 0;
	end_cp = end;
	s[end_cp--] = '\0';
	while (end_cp >= start)
	{
		buffer = n % 10 + 48;
		s[end_cp--] = buffer;
		n /= 10;
	}
}

static void	ft_print_condition(char *s, int n, int s_len)
{
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	else if (n < 0)
	{
		s[0] = '-';
		ft_fill_s(s, -n, s_len, 1);
	}
	else
		ft_fill_s(s, n, s_len, 0);
}

static int	ft_count_dec(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		result++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		s_len;

	if (n == -2147483648)
	{
		s = malloc(12 * sizeof(char));
		if (!s)
			return (0);
		s[0] = '-';
		ft_fill_s(s, 147483648, 11, 1);
		s[1] = '2';
	}
	else
	{
		s_len = ft_count_dec(n);
		s = malloc(s_len * sizeof(char) + 1);
		if (!s)
			return (0);
		ft_print_condition(s, n, s_len);
	}
	return (s);
}
