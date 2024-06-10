/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:08:09 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 14:22:55 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (0);
	return (1);
}

long long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (ft_issign(nptr[i]) == 0)
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - 48;
	return (result * sign);
}
