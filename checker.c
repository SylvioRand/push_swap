/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:48:10 by srandria          #+#    #+#             */
/*   Updated: 2024/06/07 10:41:31 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
	if (fill_position(pile_a) == -1)
		return (ft_lstclear(pile_a, pile_b), 0);
	read_stdin_instruction(&pile_a, &pile_b);
	check_is_sort(pile_a, pile_b);
	return (ft_lstclear(pile_a, pile_b), 0);
}
