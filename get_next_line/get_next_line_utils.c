/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:27:38 by srandria          #+#    #+#             */
/*   Updated: 2024/03/18 17:09:05 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (s1)
	{
		while (s1[++cursor])
			addr[++i] = ((char *)s1)[cursor];
	}
	cursor = -1;
	while (s2[++cursor])
		addr[++i] = ((char *)s2)[cursor];
	addr[++i] = '\0';
	return (addr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*addr;

	if (!s)
		return (0);
	addr = malloc(len + 1);
	if (addr == 0)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		addr[i] = s[start + i];
		i++;
	}
	addr[i] = '\0';
	return (addr);
}

int	backslash_n_pos(char *buff)
{
	int	i;

	i = -1;
	if (!buff)
		return (-1);
	while (buff[++i])
	{
		if (buff[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*strcpy_from_i(char *str, int start)
{
	char	*new;
	int		i;	

	i = -1;
	new = malloc((ft_strlen(str + start) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (!new)
		return (0);
	while (str[start])
	{
		new[++i] = str[start++];
	}
	new[++i] = '\0';
	return (new);
}
