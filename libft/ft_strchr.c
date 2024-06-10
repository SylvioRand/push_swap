/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:21:55 by srandria          #+#    #+#             */
/*   Updated: 2024/03/01 18:30:15 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = (char *)s;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (ptr + i);
	}
	if ((char)c == '\0')
		return (ptr + i);
	return (0);
}
