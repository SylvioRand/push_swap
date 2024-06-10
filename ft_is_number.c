/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:59:19 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 10:59:35 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]) == 2048)
			i++;
		else if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
			return (1);
		if (str[i] == '\n')
			return (0);
	}
	return (0);
}
