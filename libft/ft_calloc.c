/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:38:05 by srandria          #+#    #+#             */
/*   Updated: 2024/03/04 17:21:30 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	i = -1;
	if ((int)nmemb < 0 && (int)size < 0)
		return (0);
	if (nmemb == 0 && (int)size < 0)
		size = 0;
	if ((int)nmemb < 0 && size == 0)
		nmemb = 0;
	if (((int)nmemb < 0 && size > 0) || (nmemb > 0 && (int)size < 0))
		return (0);
	ptr = malloc (nmemb * size);
	if (!ptr)
		return (0);
	while (++i < (int)nmemb * (int)size)
		ptr[i] = 0;
	return (ptr);
}
