/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_to_pile_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:36:16 by srandria          #+#    #+#             */
/*   Updated: 2024/06/04 16:03:22 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_c_up_in_b(t_list *pile_b, int c_up)
{
	while (pile_b != NULL)
	{
		if (pile_b->direction == c_up)
			return (1);
		pile_b = pile_b->next;
	}
	return (0);
}

void	condition_push(t_list **pile_a, t_list **pile_b, int c_up, int c_down)
{
	if (c_up == 5)
	{
		if ((*pile_a)->direction == c_up && *pile_b)
		{
			while ((*pile_b)->direction == c_down && is_c_up_in_b(*pile_b,
					c_up) == 1)
				ft_rotate_b(pile_b);
			ft_push_b(pile_a, pile_b);
		}
		else
			ft_push_b(pile_a, pile_b);
	}
	else
	{
		if ((*pile_a)->direction == c_up && *pile_b)
		{
			while ((*pile_b)->direction == c_down)
				ft_rotate_b(pile_b);
			ft_push_b(pile_a, pile_b);
		}
		else
			ft_push_b(pile_a, pile_b);
	}
}

void	send_rest_c_up_at_end(t_list **pile_b, int c_down)
{
	while ((*pile_b)->direction == c_down)
		ft_rotate_b(pile_b);
}

void	pusher_to_b(t_list **pile_a, t_list **pile_b, t_chunk_level info)
{
	int	status;
	int	end;

	status = 0;
	end = pos_last_elemt_to_push(pile_a);
	while (1)
	{
		if ((*pile_a)->position == end)
			status = 1;
		if ((*pile_a)->direction == info.c_down
			|| (*pile_a)->direction == info.c_up)
		{
			if (not_to_push(*pile_a, info.argc) == 0)
				ft_rotate_a(pile_a);
			else
				condition_push(pile_a, pile_b, info.c_up, info.c_down);
		}
		else
			ft_rotate_a(pile_a);
		if (status == 1)
		{
			send_rest_c_up_at_end(pile_b, info.c_down);
			break ;
		}
	}
}

void	push_to_b(t_list **pile_a, t_list **pile_b)
{
	int				nb_chunk;
	t_chunk_level	info;

	nb_chunk = 8;
	info.c_down = (nb_chunk / 2);
	info.c_up = info.c_down + 1;
	info.argc = get_nb_element_in_pile(*pile_a);
	while (info.c_up <= nb_chunk)
	{
		pusher_to_b(pile_a, pile_b, info);
		info.c_up++;
		info.c_down--;
	}
}
