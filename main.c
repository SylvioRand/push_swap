/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:06:55 by srandria          #+#    #+#             */
/*   Updated: 2024/06/07 15:29:34 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_if_sort(t_list *pile_a, t_list *pile_b)
{
	if (pile_b == NULL && pile_a && pile_a->next == NULL)
		return (0);
	while (pile_a != NULL && pile_a->next)
	{
		if (pile_a->next && pile_a->position > pile_a->next->position)
			return (1);
		pile_a = pile_a->next;
	}
	if (pile_b != NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (argc == 1)
		return (0);
	var.argc = ft_create_list(argc, argv, &pile_a);
	if (var.argc == -1)
	{
		ft_printf("Error\n");
		return (ft_lstclear(pile_a, pile_b), 0);
	}
	if (var.argc == 1 || fill_position(pile_a) == -1)
		return (ft_lstclear(pile_a, pile_b), 0);
	if (check_if_sort(pile_a, pile_b) == 0)
		return (ft_lstclear(pile_a, pile_b), 0);
	ft_sort_list(&pile_a, &pile_b, &var);
	return (ft_lstclear(pile_a, pile_b), 0);
}
