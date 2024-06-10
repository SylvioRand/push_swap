/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:02:54 by srandria          #+#    #+#             */
/*   Updated: 2024/06/07 15:24:49 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_is_sort(t_list *pile_a, t_list *pile_b)
{
	if (pile_b == NULL && pile_a && pile_a->next == NULL)
	{
		ft_printf("OK\n");
		return ;
	}
	while (pile_a != NULL && pile_a->next)
	{
		if (pile_a->next && pile_a->position > pile_a->next->position)
		{
			ft_printf("KO\n");
			return ;
		}
		pile_a = pile_a->next;
	}
	if (pile_b == NULL)
		ft_printf("OK\n");
	else if (pile_b != NULL)
		ft_printf("KO\n");
	return ;
}

void	exec_cmd(char *cmd, t_list **pile_a, t_list **pile_b)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		ft_swap_a(pile_a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		ft_swap_b(pile_b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ft_swap_a_b(pile_a, pile_b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		ft_push_a(pile_a, pile_b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		ft_push_b(pile_a, pile_b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ft_rotate_a(pile_a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		ft_rotate_b(pile_b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		ft_rotate_a_b(pile_a, pile_b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		ft_reverse_rotate_a(pile_a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		ft_reverse_rotate_b(pile_b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		ft_reverse_rotate_a_b(pile_a, pile_b);
}

int	check_is_cmd_valide(char *cmd)
{
	int	status;

	status = 0;
	if (ft_strncmp(cmd, "sa\n", 3) != 0 && ft_strncmp(cmd, "sb\n", 3) != 0
		&&ft_strncmp(cmd, "ss\n", 3) != 0 && ft_strncmp(cmd, "pa\n", 3) != 0
		&& ft_strncmp(cmd, "pb\n", 3) != 0 && ft_strncmp(cmd, "ra\n", 3) != 0
		&& ft_strncmp(cmd, "rb\n", 3) != 0 && ft_strncmp(cmd, "rr\n", 3) != 0
		&& ft_strncmp(cmd, "rra\n", 4) != 0 && ft_strncmp(cmd, "rrb\n", 4) != 0
		&& ft_strncmp(cmd, "rrr\n", 4) != 0)
		status = 1;
	if (status == 1)
		return (-1);
	return (0);
}

void	read_stdin_instruction(t_list **pile_a, t_list **pile_b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == 0)
			break ;
		if (cmd == NULL)
			return ;
		if (check_is_cmd_valide(cmd) == -1)
		{
			ft_lstclear(*pile_a, *pile_b);
			exit (0);
		}
		exec_cmd(cmd, pile_a, pile_b);
		free(cmd);
	}
}
