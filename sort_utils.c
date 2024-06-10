/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:45:50 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 13:25:03 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_cursor_first(t_list *pile_a)
{
	int	cursor;

	cursor = -1;
	while (pile_a != NULL)
	{
		cursor++;
		if (pile_a->position == 1)
			return (cursor);
		pile_a = pile_a->next;
	}
	return (cursor);
}

void	fill_direction(t_list **pile_a)
{
	int		nb_chunk;
	t_list	*ptr;
	int		i;
	int		pivot;
	int		argc;

	nb_chunk = 8;
	i = -1;
	argc = get_nb_element_in_pile(*pile_a);
	while (++i < nb_chunk)
	{
		pivot = (argc / nb_chunk) * i;
		ptr = *pile_a;
		while (ptr != NULL)
		{
			if (ptr->position >= pivot)
				ptr->direction = i + 1;
			ptr = ptr->next;
		}
	}
}

void	finalisation(t_list **pile_a, int argc)
{
	int	cursor;

	cursor = get_cursor_first(*pile_a);
	if (cursor < argc - cursor)
	{
		while (cursor-- > 0)
		{
			ft_rotate_a(pile_a);
		}
	}
	else
	{
		cursor = argc - cursor;
		while (cursor-- > 0)
		{
			ft_reverse_rotate_a(pile_a);
		}
	}
}
