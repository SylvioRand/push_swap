/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:07:24 by srandria          #+#    #+#             */
/*   Updated: 2024/06/06 11:52:35 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*ptr;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new_node;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new_node;
}
