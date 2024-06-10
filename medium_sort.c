/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:13:14 by srandria          #+#    #+#             */
/*   Updated: 2024/06/04 16:02:06 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_sort_three_elt(t_list **pile_a, int argc)
{
	t_list	*a_ptr;

	a_ptr = *pile_a;
	if (a_ptr->position == argc)
	{
		if (a_ptr->next->position == argc - 1)
		{
			ft_swap_a(pile_a);
			ft_reverse_rotate_a(pile_a);
		}
		else if (a_ptr->next->position == argc - 2)
			ft_rotate_a(pile_a);
	}
	else if (a_ptr->position == argc - 1)
	{
		if (a_ptr->next->position == argc)
			ft_reverse_rotate_a(pile_a);
		else if (a_ptr->next->position == argc - 2)
			ft_swap_a(pile_a);
	}
	else if (a_ptr->next->position == argc)
	{
		ft_reverse_rotate_a(pile_a);
		ft_swap_a(pile_a);
	}
}

void	sort_medium_list(t_list **pile_a, t_list **pile_b, int argc)
{
	while (1)
	{
		if (get_nb_element_in_pile(*pile_a) == 3)
			break ;
		if ((*pile_a)->position != argc
			&& (*pile_a)->position != argc - 1
			&& (*pile_a)->position != argc - 2)
			ft_push_b(pile_a, pile_b);
		else
			ft_rotate_a(pile_a);
	}
	ft_sort_three_elt(pile_a, argc);
}
