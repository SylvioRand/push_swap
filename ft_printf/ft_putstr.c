/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:24:31 by srandria          #+#    #+#             */
/*   Updated: 2024/04/08 19:51:56 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_putstr(char *str)
{
	int		i;
	int		count;
	char	c;

	i = -1;
	count = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (*(str + ++i) != '\0')
	{
		c = *(str + i);
		count += (int)write(1, &c, 1);
	}
	return (count);
}
