/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:52:51 by srandria          #+#    #+#             */
/*   Updated: 2024/05/13 10:02:04 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_elt;

	new_elt = ft_calloc(1, sizeof(t_list));
	if (!new_elt)
		return (0);
	new_elt->value = content;
	new_elt->next = 0;
	return (new_elt);
}
