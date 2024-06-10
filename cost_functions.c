/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 07:47:49 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 13:08:43 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	cost_double_up(int a_curs, int b_curs)
{
	if (a_curs >= b_curs)
		return (a_curs);
	return (b_curs);
}

int	cost_double_down(t_list *pile_a, t_list *pile_b, int a_curs, int b_curs)
{
	int	nb_elt_a;
	int	nb_elt_b;

	nb_elt_a = get_nb_element_in_pile(pile_a);
	nb_elt_b = get_nb_element_in_pile(pile_b);
	if (nb_elt_a - a_curs >= nb_elt_b - b_curs)
		return (nb_elt_a - a_curs);
	return (nb_elt_b - b_curs);
}

int	cost_individual_b_up(t_list *pile_a, int a_curs, int b_curs)
{
	int	cost;
	int	nb_elt_a;

	nb_elt_a = get_nb_element_in_pile(pile_a);
	cost = (nb_elt_a - a_curs) + b_curs;
	return (cost);
}

int	cost_individual_b_down(t_list *pile_b, int a_curs,
		int b_curs)
{
	int	cost;
	int	nb_elt_b;

	nb_elt_b = get_nb_element_in_pile(pile_b);
	cost = (nb_elt_b - b_curs) + a_curs;
	return (cost);
}
