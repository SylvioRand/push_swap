/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:32:26 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 11:09:11 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_if_in_set(char	*set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (0);
	}
	return (1);
}

static int	ft_get_trim_start(char *s1, char *set)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (ft_check_if_in_set(set, s1[i]) == 1)
			return (i);
	}
	if (s1[i] == '\0')
		return (-2);
	return (0);
}

static int	ft_get_trim_end(char *s1, char *set)
{
	int	end;

	end = ft_strlen(s1);
	while (--end >= 0)
	{
		if (ft_check_if_in_set(set, s1[end]) == 1)
			return (end + 1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*s;

	i = -1;
	start = ft_get_trim_start((char *)s1, (char *)set);
	if (start == -2)
	{
		s = malloc(sizeof(char));
		if (s == 0)
			return (0);
		s[0] = '\0';
		return (s);
	}
	end = ft_get_trim_end((char *)s1, (char *)set);
	s = malloc ((end - start + 1) * sizeof(char));
	if (s == 0)
		return (0);
	while (start < end)
		s[++i] = s1[start++];
	s[++i] = '\0';
	return (s);
}
