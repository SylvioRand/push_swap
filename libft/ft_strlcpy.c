/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:43:22 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:08:14 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*src_copy;

	src_copy = (char *)src;
	i = 0;
	if (size == 0)
		return (ft_strlen(src_copy));
	while (src_copy[i] != '\0' && i < size - 1)
	{
		dst[i] = src_copy[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src_copy));
}
