/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:53:01 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 13:09:12 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	process_get_info_a(t_list *pile_a, t_elmt_info **a_elemt, int b_pos)
{
	int	i;

	i = -1;
	while (pile_a != NULL)
	{
		i++;
		if (pile_a->next && pile_a->position < b_pos
			&& b_pos < pile_a->next->position)
		{
			(*a_elemt)->position = pile_a->next->position;
			(*a_elemt)->cursor = i + 1;
			break ;
		}
		else if (pile_a->next == NULL)
		{
			(*a_elemt)->cursor = 0;
		}
		pile_a = pile_a->next;
	}
}

void	get_elemt_info_a(t_list *pile_a, t_elmt_info *a_elemt, int b_pos)
{
	if (pile_a == NULL || pile_a->next == NULL)
	{
		a_elemt->cursor = 0;
		return ;
	}
	if (b_pos < get_min_pile(pile_a) || b_pos > get_max_pile(pile_a))
	{
		get_cursor_min(pile_a, a_elemt);
		return ;
	}
	process_get_info_a(pile_a, &a_elemt, b_pos);
}

void	fill_cur_el(t_el_to_move **cur_el, int a_cur, int a_pos, int schema)
{
	(*cur_el)->cursor_a = a_cur;
	(*cur_el)->a_pos = a_pos;
	(*cur_el)->schema = schema;
}

int	get_cost(t_list *pile_a, t_list *pile_b, t_el_to_move *cur_el)
{
	int			cost;
	int			schema;
	t_elmt_info	a_el;
	int			a_cur;

	get_elemt_info_a(pile_a, &a_el, cur_el->b_pos);
	a_cur = a_el.cursor;
	cost = cost_double_up(a_cur, cur_el->cursor_b);
	schema = 11;
	if (cost_double_down(pile_a, pile_b, a_cur, cur_el->cursor_b) < cost)
	{
		cost = cost_double_down(pile_a, pile_b, a_cur, cur_el->cursor_b);
		schema = 22;
	}
	if (cost_individual_b_up(pile_a, a_cur, cur_el->cursor_b) < cost)
	{
		cost = cost_individual_b_up(pile_a, a_cur, cur_el->cursor_b);
		schema = 12;
	}
	if (cost_individual_b_down(pile_b, a_cur, cur_el->cursor_b) < cost)
	{
		cost = cost_individual_b_down(pile_b, a_cur, cur_el->cursor_b);
		schema = 21;
	}
	return (fill_cur_el(&cur_el, a_cur, a_el.position, schema), cost);
}
