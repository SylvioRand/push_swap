/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:09:10 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 14:29:52 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_for_select(t_list *pile_b, t_select *vars)
{
	vars->status = 0;
	vars->i = 0;
	vars->pile_b_ptr = pile_b;
}

void	select_status_zero(t_list *pile_a, t_list *pile_b, t_select *vars,
	t_el_to_move *cur_el)
{
	cur_el->a_pos = 0;
	cur_el->b_pos = pile_b->position;
	cur_el->cursor_b = vars->i;
	vars->cost = get_cost(pile_a, vars->pile_b_ptr, cur_el);
}

void	select_status_one(t_list *pile_a, t_list *pile_b, t_select *vars,
	t_el_to_move *cur_el)
{
	cur_el->b_pos = pile_b->position;
	cur_el->cursor_b = vars->i;
	vars->cur_cost = get_cost(pile_a, vars->pile_b_ptr, cur_el);
}

void	ft_select(t_list *pile_a, t_list *pile_b, t_el_to_move *elements,
	t_chunk_p **data)
{
	t_select		vars;
	t_el_to_move	cur_el;

	init_for_select(pile_b, &vars);
	while (pile_b != NULL)
	{
		if (pile_b->position >= (*data)->pivot)
		{
			if (vars.status == 0)
			{
				select_status_zero(pile_a, pile_b, &vars, &cur_el);
				updater(&elements, cur_el, &vars);
			}
			else if (vars.status == 1)
			{
				select_status_one(pile_a, pile_b, &vars, &cur_el);
				updater(&elements, cur_el, &vars);
			}
		}
		vars.i++;
		pile_b = pile_b->next;
	}
}
