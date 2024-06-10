/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:59:19 by srandria          #+#    #+#             */
/*   Updated: 2024/06/05 15:16:18 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstclear(t_list *pile_a, t_list *pile_b)
{
	t_list	*next_a;
	t_list	*next_b;

	while (pile_a != NULL)
	{
		next_a = pile_a->next;
		free (pile_a);
		pile_a = next_a;
	}
	while (pile_b != NULL)
	{
		next_b = pile_b->next;
		free (pile_b);
		pile_b = next_b;
	}
}
