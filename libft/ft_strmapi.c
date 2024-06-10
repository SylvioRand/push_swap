/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:53:56 by srandria          #+#    #+#             */
/*   Updated: 2024/03/06 07:42:19 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_len;
	char	*s_new;
	char	buffer;

	i = -1;
	s_len = ft_strlen(s);
	s_new = malloc(s_len * sizeof(char) + 1);
	if (!s_new)
		return (0);
	while (s[++i])
	{
		buffer = (*f)(i, s[i]);
		s_new[i] = buffer;
	}
	s_new[i] = '\0';
	return (s_new);
}
