/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 07:23:52 by srandria          #+#    #+#             */
/*   Updated: 2024/06/07 10:41:44 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_error_input(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '-')
			return (-1);
		else if (str[i] == '-' && str[i + 1] && ft_isdigit(str[i + 1]) == 0)
			return (-1);
		else if (str[i] == '-' && !str[i + 1])
			return (-1);
	}
	return (0);
}

int	check_no_overflow(char *str)
{
	if (ft_atol(str) > 2147483647
		|| ft_atol(str) < (long)(-2147483648))
		return (-1);
	return (0);
}

int	add_elements_to_list(char **splitted, t_list **pile_a)
{
	int		i;
	t_list	*new_elt;

	i = -1;
	if (*splitted == NULL)
		return (-1);
	while (splitted[++i] != NULL)
	{
		if (check_no_overflow(splitted[i]) == -1)
			return (-1);
		new_elt = ft_lstnew(ft_atoi(splitted[i]));
		if (new_elt == NULL)
			return (-1);
		new_elt->position = 1;
		ft_lstadd_back(pile_a, new_elt);
	}
	return (0);
}

int	ft_create_list(int argc, char **argv, t_list **pile_a)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = NULL;
	while (++i <= argc - 1)
	{
		if (check_error_input(argv[i]) == -1)
			return (-1);
		splitted = ft_split(argv[i], ' ');
		if (splitted == NULL)
			return (-1);
		if (add_elements_to_list(splitted, pile_a) == -1)
			return (free_split(splitted), -1);
		free_split(splitted);
	}
	return (get_nb_element_in_pile(*pile_a));
}

int	fill_position(t_list *pile_a)
{
	t_list	*fixed_node;
	t_list	*cursor;

	fixed_node = pile_a;
	while (fixed_node != 0)
	{
		cursor = pile_a;
		while (cursor != 0)
		{
			if (cursor->value == fixed_node->value && cursor != fixed_node)
			{
				ft_printf("Error\n");
				return (-1);
			}
			if (cursor->value > fixed_node->value)
				cursor->position += 1;
			cursor = cursor->next;
		}
		fixed_node = fixed_node->next;
	}
	return (0);
}
