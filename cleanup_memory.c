/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 07:23:38 by srandria          #+#    #+#             */
/*   Updated: 2024/06/07 07:23:41 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_nb_element_list(char **list)
{
	int	i;

	i = -1;
	while (list[++i] != NULL)
		;
	return (i);
}

void	free_split(char **list)
{
	int	nb_el;

	nb_el = 0;
	if (list != NULL)
		nb_el = get_nb_element_list(list) - 1;
	while (nb_el >= 0)
	{
		free(list[nb_el]);
		list[nb_el] = NULL;
		nb_el--;
	}
	free (list);
}
