/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 07:31:30 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 11:26:54 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_swap_a(t_list **pile_a)
{
	t_list	*ptr;
	t_list	*ptr2;
	t_list	*ptr3;

	if (*pile_a == NULL)
		return ;
	ft_printf("sa\n");
	ptr = *pile_a;
	ptr2 = ptr->next;
	if (ptr2 == NULL)
		return ;
	ptr3 = ptr2->next;
	ptr2->next = ptr;
	ptr->next = ptr3;
	*pile_a = ptr2;
}

void	ft_swap_b(t_list **pile_b)
{
	t_list	*ptr;
	t_list	*ptr2;
	t_list	*ptr3;

	if (*pile_b == NULL)
		return ;
	ft_printf("sb\n");
	ptr = *pile_b;
	ptr2 = ptr->next;
	if (ptr2 == NULL)
		return ;
	ptr3 = ptr2->next;
	ptr2->next = ptr;
	ptr->next = ptr3;
	*pile_b = ptr2;
}

void	ft_swap_a_b(t_list **pile_a, t_list **pile_b)
{
	t_list	*ptr;
	t_list	*ptr2;
	t_list	*ptr3;

	ft_printf("ss\n");
	ptr = *pile_a;
	ptr2 = ptr->next;
	if (ptr2 == NULL)
		return ;
	ptr3 = ptr2->next;
	ptr2->next = ptr;
	ptr->next = ptr3;
	*pile_a = ptr2;
	ptr = *pile_b;
	ptr2 = ptr->next;
	if (ptr2 == NULL)
		return ;
	ptr3 = ptr2->next;
	ptr2->next = ptr;
	ptr->next = ptr3;
	*pile_b = ptr2;
}
