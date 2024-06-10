/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:15:30 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:09:24 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*addr;

	if (!s)
		return (0);
	s_len = ft_strlen((char *)s);
	if (s_len == 0)
		len = 0;
	if (start > s_len - 1)
		len = 0;
	else if (len > (s_len - start))
		len = s_len - start;
	addr = malloc(len + 1);
	if (addr == 0)
		return (0);
	i = -1;
	while (++i < len)
		addr[i] = s[start++];
	addr[i] = '\0';
	return (addr);
}
