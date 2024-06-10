/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:46:29 by srandria          #+#    #+#             */
/*   Updated: 2024/06/04 18:35:59 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_chunk_in_pile(t_list *pile, int pivot)
{
	while (pile != NULL)
	{
		if (pile->position >= pivot)
			return (1);
		pile = pile->next;
	}
	return (0);
}

void	ft_mover(t_list **pile_a, t_list **pile_b, t_el_to_move elements)
{
	if (elements.schema == 11)
		dual_move_up(pile_a, pile_b, elements);
	else if (elements.schema == 22)
		dual_move_down(pile_a, pile_b, elements);
	else if (elements.schema == 12)
		indiv_move_up(pile_a, pile_b, elements);
	else if (elements.schema == 21)
		indiv_move_down(pile_a, pile_b, elements);
}

void	sort_process(t_list **pile_a, t_list **pile_b, t_chunk_p *data)
{
	t_el_to_move	elements;
	int				i;

	data->pivot = (data->argc / 8) * (data->chunk);
	i = 0;
	while (is_chunk_in_pile(*pile_b, data->pivot) == 1)
	{
		i++;
		ft_select(*pile_a, *pile_b, &elements, &data);
		ft_mover(pile_a, pile_b, elements);
		ft_push_a(pile_a, pile_b);
	}
}

void	sorting_algo(t_list **pile_a, t_list **pile_b, int argc)
{
	int			nb_chunk;
	t_chunk_p	chunk_part;

	nb_chunk = 8;
	chunk_part.argc = argc;
	chunk_part.chunk = 7;
	while (--nb_chunk >= 0)
	{
		chunk_part.chunk = nb_chunk;
		sort_process(pile_a, pile_b, &chunk_part);
	}
}

void	ft_sort_list(t_list **pile_a, t_list **pile_b, t_var *var)
{
	fill_direction(pile_a);
	if (var->argc == 2)
	{
		if ((*pile_a)->position > (*pile_a)->next->position)
			ft_swap_a(pile_a);
		return ;
	}
	if (var->argc <= 20)
		sort_medium_list(pile_a, pile_b, var->argc);
	else
	{
		push_to_b(pile_a, pile_b);
		ft_sort_three_elt(pile_a, var->argc);
	}
	sorting_algo(pile_a, pile_b, var->argc);
	finalisation(pile_a, var->argc);
}
