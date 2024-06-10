/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:03:29 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:07:51 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i;
	int		cursor;
	char	*addr;

	total_len = ft_strlen(s1);
	total_len = ft_strlen(s2) + total_len;
	addr = malloc(total_len + 1);
	if (addr == 0)
		return (0);
	i = -1;
	cursor = -1;
	while (s1[++cursor])
		addr[++i] = ((char *)s1)[cursor];
	cursor = -1;
	while (s2[++cursor])
		addr[++i] = ((char *)s2)[cursor];
	addr[++i] = '\0';
	return (addr);
}
