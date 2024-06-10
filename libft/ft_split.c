/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:52:30 by srandria          #+#    #+#             */
/*   Updated: 2024/03/07 16:44:54 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_string(char *s, char c)
{
	int	i;
	int	result;
	int	status;

	status = 1;
	result = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (status == 1)
			{
				status = 0;
				result++;
			}
		}
		else if (s[i] == c)
			status = 1;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*start_bloc;
	int		len;
	int		i;

	i = -1;
	tab = malloc((ft_nb_string((char *)s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (0);
	while (*s)
	{
		while (*s == c)
			++s;
		len = 0;
		start_bloc = (char *)s;
		while (*s != c && *s && s++)
			len++;
		if (len > 0)
			tab[++i] = ft_substr(start_bloc, 0, len);
	}
	tab[++i] = 0;
	return (tab);
}
