/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:29:01 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:07:30 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;
	char	*addr;

	i = -1;
	ptr = (char *)s;
	addr = malloc(ft_strlen(ptr) + 1);
	if (addr == 0)
		return (0);
	while (ptr[++i])
	{
		addr[i] = ptr[i];
	}
	addr[i] = '\0';
	return (addr);
}
