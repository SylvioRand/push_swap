/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 07:27:51 by srandria          #+#    #+#             */
/*   Updated: 2024/06/03 12:52:44 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_push_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*ptr;

	if (pile_b == NULL || *pile_b == NULL)
		return ;
	ft_printf("pa\n");
	ptr = *pile_b;
	*pile_b = (*pile_b)->next;
	ptr->next = *pile_a;
	*pile_a = ptr;
}

void	ft_push_b(t_list **pile_a, t_list **pile_b)
{
	t_list	*ptr;

	if (pile_a == NULL || *pile_a == NULL)
		return ;
	ft_printf("pb\n");
	ptr = *pile_a;
	*pile_a = (*pile_a)->next;
	ptr->next = *pile_b;
	*pile_b = ptr;
}
