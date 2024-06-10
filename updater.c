/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:13:42 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 14:33:24 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	update_elmts_to_m(t_el_to_move **elements, t_el_to_move *cur_el,
	t_select **vars, int status)
{
	(*elements)->cursor_a = cur_el->cursor_a;
	(*elements)->a_pos = cur_el->a_pos;
	(*elements)->b_pos = cur_el->b_pos;
	(*elements)->cursor_b = cur_el->cursor_b;
	(*elements)->schema = cur_el->schema;
	if (status == 1)
		(*vars)->cost = (*vars)->cur_cost;
}

void	updater(t_el_to_move **elements, t_el_to_move cur_el, t_select *vars)
{
	if (vars->status == 1)
	{
		if (vars->cur_cost < vars->cost
			&& cur_el.b_pos >= (*elements)->b_pos - 5)
		{
			update_elmts_to_m(elements, &cur_el, &vars, 1);
		}
		else if (vars->cur_cost == vars->cost)
		{
			if (cur_el.b_pos > (*elements)->b_pos)
				update_elmts_to_m(elements, &cur_el, &vars, 1);
		}
		else if (vars->cur_cost <= vars->cost - 3)
		{
			if (cur_el.b_pos > (*elements)->b_pos)
				update_elmts_to_m(elements, &cur_el, &vars, 1);
		}
	}
	if (vars->status == 0)
	{
		vars->status = 1;
		update_elmts_to_m(elements, &cur_el, &vars, 0);
	}
}
