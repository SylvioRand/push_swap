/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:58:45 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 10:36:36 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*addr;

	i = 0;
	addr = (unsigned char *)s;
	while (i < n)
	{
		if (addr[i] == (unsigned char)c)
			return (addr + i);
		i++;
	}
	return (0);
}
