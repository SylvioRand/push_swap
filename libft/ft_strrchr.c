/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:19:07 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:07:12 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;
	char	*ptr;

	i = -1;
	pos = -1;
	ptr = (char *)s;
	while (s[++i])
	{
		if (s[i] == (char)c)
			pos = i;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	if (pos != -1)
		return (ptr + pos);
	else if (i == 0 && (char)c == '\0')
		return (ptr);
	return (0);
}
