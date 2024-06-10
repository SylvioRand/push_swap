/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 07:38:37 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 12:53:36 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_reverse_rotate_a(t_list **pile_a)
{
	t_list	*ptr_end;
	t_list	*ptr_bef_end;

	if (pile_a == 0 || *pile_a == 0)
		return ;
	ptr_bef_end = *pile_a;
	if ((*pile_a)->next == 0)
		return ;
	ft_printf("rra\n");
	ptr_end = ft_lstlast(*pile_a);
	while (ptr_bef_end != NULL)
	{
		if (ptr_bef_end->next == ptr_end)
		{
			ptr_bef_end->next = NULL;
			break ;
		}
		ptr_bef_end = ptr_bef_end->next;
	}
	ptr_end->next = *pile_a;
	*pile_a = ptr_end;
}

void	ft_reverse_rotate_a_np(t_list **pile_a)
{
	t_list	*ptr_end;
	t_list	*ptr_bef_end;

	if (pile_a == 0 || *pile_a == 0)
		return ;
	ptr_bef_end = *pile_a;
	if ((*pile_a)->next == 0)
		return ;
	ptr_end = ft_lstlast(*pile_a);
	while (ptr_bef_end != NULL)
	{
		if (ptr_bef_end->next == ptr_end)
		{
			ptr_bef_end->next = NULL;
			break ;
		}
		ptr_bef_end = ptr_bef_end->next;
	}
	ptr_end->next = *pile_a;
	*pile_a = ptr_end;
}

void	ft_reverse_rotate_b(t_list **pile_b)
{
	t_list	*ptr_end;
	t_list	*ptr_bef_end;

	if (pile_b == 0 || *pile_b == 0)
		return ;
	ptr_bef_end = *pile_b;
	if ((*pile_b)->next == 0)
		return ;
	ft_printf("rrb\n");
	ptr_end = ft_lstlast(*pile_b);
	while (ptr_bef_end != NULL)
	{
		if (ptr_bef_end->next == ptr_end)
		{
			ptr_bef_end->next = NULL;
			break ;
		}
		ptr_bef_end = ptr_bef_end->next;
	}
	ptr_end->next = *pile_b;
	*pile_b = ptr_end;
}

void	ft_reverse_rotate_b_np(t_list **pile_b)
{
	t_list	*ptr_end;
	t_list	*ptr_bef_end;

	if (pile_b == 0 || *pile_b == 0)
		return ;
	ptr_bef_end = *pile_b;
	if ((*pile_b)->next == 0)
		return ;
	ptr_end = ft_lstlast(*pile_b);
	while (ptr_bef_end != NULL)
	{
		if (ptr_bef_end->next == ptr_end)
		{
			ptr_bef_end->next = NULL;
			break ;
		}
		ptr_bef_end = ptr_bef_end->next;
	}
	ptr_end->next = *pile_b;
	*pile_b = ptr_end;
}

void	ft_reverse_rotate_a_b(t_list **pile_a, t_list **pile_b)
{
	if (pile_a == 0 || pile_b == 0 || *pile_a == 0 || *pile_b == 0)
		return ;
	if ((*pile_a)->next == NULL || (*pile_b)->next == NULL)
		return ;
	ft_printf("rrr\n");
	ft_reverse_rotate_a_np(pile_a);
	ft_reverse_rotate_b_np(pile_b);
}
