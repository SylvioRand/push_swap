/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 07:36:29 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 11:26:35 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_rotate_a(t_list **pile_a)
{
	t_list	*ptr;
	t_list	*ptr_end;

	if (pile_a == NULL || *pile_a == NULL)
		return ;
	if ((*pile_a)->next == 0)
		return ;
	ft_printf("ra\n");
	ptr = *pile_a;
	ptr_end = ft_lstlast(*pile_a);
	ptr_end->next = ptr;
	*pile_a = ptr->next;
	ptr->next = NULL;
}

void	ft_rotate_b(t_list **pile_b)
{
	t_list	*ptr;
	t_list	*ptr_end;

	if (pile_b == NULL || *pile_b == NULL)
		return ;
	if ((*pile_b)->next == 0)
		return ;
	ft_printf("rb\n");
	ptr = *pile_b;
	ptr_end = ft_lstlast(*pile_b);
	ptr_end->next = ptr;
	*pile_b = ptr->next;
	ptr->next = NULL;
}

void	ft_rotate_a_b(t_list **pile_a, t_list **pile_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	t_list	*ptr_end_a;
	t_list	*ptr_end_b;

	if (pile_a == 0 || *pile_a == 0 || pile_b == 0 || *pile_b == 0)
		return ;
	ft_printf("rr\n");
	if (pile_b == NULL || *pile_b == NULL)
		return ;
	if ((*pile_b)->next == 0)
		return ;
	ptr_a = *pile_a;
	ptr_b = *pile_b;
	ptr_end_a = ft_lstlast(*pile_a);
	ptr_end_b = ft_lstlast(*pile_b);
	ptr_end_a->next = ptr_a;
	ptr_end_b->next = ptr_b;
	*pile_a = ptr_a->next;
	*pile_b = ptr_b->next;
	ptr_b->next = NULL;
	ptr_a->next = NULL;
}
