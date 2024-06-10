/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:36:34 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:08:38 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_buffer;
	unsigned char	*s2_buffer;

	i = 0;
	s1_buffer = (unsigned char *)s1;
	s2_buffer = (unsigned char *)s2;
	while (i < n && s1[i])
	{
		if (s1[i] != s2[i])
			return (s1_buffer[i] - s2_buffer[i]);
		i++;
	}
	if (s1[i] != s2[i] && i < n)
		return (s1_buffer[i] - s2_buffer[i]);
	return (0);
}
