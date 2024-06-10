/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movers_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:02 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 14:25:33 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	dual_move_up(t_list **pile_a, t_list **pile_b, t_el_to_move elements)
{
	int	move_a;
	int	move_b;

	move_a = elements.cursor_a;
	move_b = elements.cursor_b;
	if (move_a >= move_b)
	{
		while (move_b-- > 0)
			ft_rotate_a_b(pile_a, pile_b);
		move_a = move_a - elements.cursor_b;
		while (move_a-- > 0)
			ft_rotate_a(pile_a);
	}
	else
	{
		while (move_a-- > 0)
			ft_rotate_a_b(pile_a, pile_b);
		move_b = move_b - elements.cursor_a;
		while (move_b-- > 0)
			ft_rotate_b(pile_b);
	}
}

void	init_for_dmd(t_list **pile_a, t_list **pile_b, t_dmd *vars,
	t_el_to_move elements)
{
	vars->nb_elt_a = get_nb_element_in_pile(*pile_a);
	vars->nb_elt_b = get_nb_element_in_pile(*pile_b);
	vars->move_a = vars->nb_elt_a - elements.cursor_a;
	vars->move_b = vars->nb_elt_b - elements.cursor_b;
}

void	dual_move_down(t_list **pile_a, t_list **pile_b, t_el_to_move elements)
{
	t_dmd	vars;

	init_for_dmd(pile_a, pile_b, &vars, elements);
	if (vars.move_a >= vars.move_b)
	{
		if (vars.nb_elt_b == 1)
			ft_reverse_rotate_a(pile_a);
		while (vars.move_b-- > 0)
			ft_reverse_rotate_a_b(pile_a, pile_b);
		vars.move_a = vars.move_a - (vars.nb_elt_b - elements.cursor_b);
		while (vars.move_a-- > 0)
			ft_reverse_rotate_a(pile_a);
	}
	else
	{
		if (vars.nb_elt_a == 1)
			ft_reverse_rotate_b(pile_b);
		while (vars.move_a-- > 0)
			ft_reverse_rotate_a_b(pile_a, pile_b);
		vars.move_b = vars.move_b - (vars.nb_elt_a - elements.cursor_a);
		while (vars.move_b-- > 0)
			ft_reverse_rotate_b(pile_b);
	}
}

void	indiv_move_up(t_list **pile_a, t_list **pile_b, t_el_to_move elements)
{
	int	nb_elt_a;
	int	nb_move_a;

	nb_elt_a = get_nb_element_in_pile(*pile_a);
	nb_move_a = nb_elt_a - elements.cursor_a;
	while (elements.cursor_b-- > 0)
	{
		ft_rotate_b(pile_b);
	}
	while (nb_move_a-- > 0)
	{
		ft_reverse_rotate_a(pile_a);
	}
}

void	indiv_move_down(t_list **pile_a, t_list **pile_b, t_el_to_move elements)
{
	int	nb_elt_b;
	int	nb_move_b;

	nb_elt_b = get_nb_element_in_pile(*pile_b);
	nb_move_b = nb_elt_b - elements.cursor_b;
	while (elements.cursor_a-- > 0)
	{
		ft_rotate_a(pile_a);
	}
	while (nb_move_b-- > 0)
	{
		ft_reverse_rotate_b(pile_b);
	}
}
