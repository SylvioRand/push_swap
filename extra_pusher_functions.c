/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_pusher_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:58:41 by srandria          #+#    #+#             */
/*   Updated: 2024/06/04 16:03:47 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pos_last_elemt_to_push(t_list **pile_a)
{
	t_list	*ptr;
	int		pos;

	ptr = *pile_a;
	while (ptr != NULL)
	{
		pos = ptr->position;
		ptr = ptr->next;
	}
	return (pos);
}

int	not_to_push(t_list *pile_a, int argc)
{
	if (pile_a->direction == 8 && (pile_a->position == argc
			|| pile_a->position == argc - 1
			|| pile_a->position == argc - 2))
		return (0);
	return (1);
}
