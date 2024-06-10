/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 07:55:27 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 12:56:11 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_min_pile(t_list *pile)
{
	int	min;

	min = pile->position;
	while (pile != NULL)
	{
		if (pile->position < min)
			min = pile->position;
		pile = pile->next;
	}
	return (min);
}

int	get_max_pile(t_list *pile)
{
	int	max;

	max = pile->position;
	while (pile != NULL)
	{
		if (pile->position > max)
			max = pile->position;
		pile = pile->next;
	}
	return (max);
}

void	get_cursor_min(t_list *pile, t_elmt_info *a_elemt)
{
	int	i;
	int	min_position;

	i = -1;
	a_elemt->position = pile->position;
	a_elemt->cursor = 0;
	min_position = pile->position;
	while (pile != NULL)
	{
		i++;
		if (pile->position < min_position)
		{
			a_elemt->position = pile->position;
			a_elemt->cursor = i;
			min_position = a_elemt->position;
		}
		pile = pile->next;
	}
}

int	get_nb_element_in_pile(t_list *pile)
{
	int	i;

	i = 0;
	if (pile == NULL)
		return (0);
	while (pile != NULL)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}
