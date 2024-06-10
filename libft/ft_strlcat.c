/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarakoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:49:16 by rarakoto          #+#    #+#             */
/*   Updated: 2024/03/06 13:23:29 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_length;
	int		j;

	i = 0;
	j = 0;
	dest_length = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	else
	{
		while (*(dst + i) != '\0' && i < size)
			i++;
		while (i < size - 1 && *(src + j))
			dst[i++] = src[j++];
		if (i < size)
			*(dst + i) = '\0';
		return (dest_length + ft_strlen(src));
	}
}
