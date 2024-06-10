/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:34:27 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:45:23 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_list(t_data *list)
{
	list->nb_int = 0;
	list->nb_uint = 0;
	list->str = 0;
	list->nb_uint_ptr = 0;
}

void	init_status(t_flags *status)
{
	status->minus = 0;
	status->plus = 0;
	status->space = 0;
	status->zero = 0;
	status->number = 0;
	status->width = 0;
	status->hashtag = 0;
	status->point = 0;
}
