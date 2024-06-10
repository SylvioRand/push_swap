/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:29:01 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:05:29 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_cpy;
	char	*src_cpy;

	i = -1;
	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (dest == 0 && src == 0)
		return (0);
	if (dest > src)
	{
		while (n-- > (size_t)0)
			dest_cpy[n] = src_cpy[n];
	}
	else
	{
		while (++i < n)
			dest_cpy[i] = src_cpy[i];
	}
	return (dest_cpy);
}
