/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 07:56:03 by srandria          #+#    #+#             */
/*   Updated: 2024/06/06 13:37:32 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf_bonus.h"
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				position;
	char			direction;
	struct s_list	*next;
}			t_list;

typedef struct s_var
{
	int	index;
	int	argc;
}			t_var;

typedef struct s_elmt_info
{
	int	cursor;
	int	position;
}			t_elmt_info;

typedef struct s_el_to_move
{
	int	a_pos;
	int	b_pos;
	int	cursor_a;
	int	cursor_b;
	int	schema;
}			t_el_to_move;

typedef struct s_chunk_p
{
	int	chunk;
	int	argc;
	int	pivot;
}			t_chunk_p;

typedef struct s_dmd
{
	int	nb_elt_a;
	int	nb_elt_b;
	int	move_a;
	int	move_b;
}			t_dmd;

typedef struct s_select
{
	int				cost;
	int				cur_cost;
	int				status;
	int				i;
	t_list			*pile_b_ptr;
}			t_select;

typedef struct s_chunk_level
{
	int	c_up;
	int	c_down;
	int	argc;
}			t_chunk_level;

long long	ft_atol(const char *nptr);
int			ft_isdigit(int c);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_node);
void		ft_lstclear(t_list *pile_a, t_list *pile_b);
void		ft_push_a(t_list **pile_a, t_list **pile_b);
void		ft_push_b(t_list **pile_a, t_list **pile_b);
void		ft_swap_a(t_list **pile_a);
void		ft_swap_b(t_list **pile_b);
void		ft_swap_a_b(t_list **pile_a, t_list **pile_b);
void		ft_rotate_a(t_list **pile_a);
void		ft_rotate_b(t_list **pile_b);
void		ft_rotate_a_b(t_list **pile_a, t_list **pile_b);
void		ft_reverse_rotate_a(t_list **pile_a);
void		ft_reverse_rotate_a_np(t_list **pile_a);
void		ft_reverse_rotate_b(t_list **pile_b);
void		ft_reverse_rotate_b_np(t_list **pile_b);
void		ft_reverse_rotate_a_b(t_list **pile_a, t_list **pile_b);
int			cost_double_up(int a_curs, int b_curs);
int			cost_double_down(t_list *pile_a, t_list *pile_b, int a_curs,
				int b_curs);
int			cost_individual_b_up(t_list *pile_a, int a_curs,
				int b_curs);
int			cost_individual_b_down(t_list *pile_b, int a_curs,
				int b_curs);
int			get_min_pile(t_list *pile);
int			get_max_pile(t_list *pile);
void		get_cursor_min(t_list *pile, t_elmt_info *a_elemt);
int			get_nb_element_in_pile(t_list *pile);
void		dual_move_up(t_list **pile_a, t_list **pile_b,
				t_el_to_move elements);
void		init_for_dmd(t_list **pile_a, t_list **pile_b, t_dmd *vars,
				t_el_to_move elements);
void		dual_move_down(t_list **pile_a, t_list **pile_b,
				t_el_to_move elements);
void		indiv_move_up(t_list **pile_a, t_list **pile_b,
				t_el_to_move elements);
void		indiv_move_down(t_list **pile_a, t_list **pile_b,
				t_el_to_move elements);
void		process_get_info_a(t_list *pile_a, t_elmt_info **a_elemt,
				int b_pos);
void		get_elemt_info_a(t_list *pile_a, t_elmt_info *a_elemt, int b_pos);
void		fill_cur_el(t_el_to_move **cur_el, int a_cur, int a_pos,
				int schema);
int			get_cost(t_list *pile_a, t_list *pile_b, t_el_to_move *cur_el);
int			ft_isnumber(char *str);
//void		*ft_extract_value(t_list **pile_a, char *argv1, t_var *var);
void		init_for_select(t_list *pile_b, t_select *vars);
void		select_status_zero(t_list *pile_a, t_list *pile_b, t_select *vars,
				t_el_to_move *cur_el);
void		select_status_one(t_list *pile_a, t_list *pile_b, t_select *vars,
				t_el_to_move *cur_el);
void		ft_select(t_list *pile_a, t_list *pile_b, t_el_to_move *elements,
				t_chunk_p **data);
void		update_elmts_to_m(t_el_to_move **elements, t_el_to_move *cur_el,
				t_select **vars, int status);
void		updater(t_el_to_move **elements, t_el_to_move cur_el,
				t_select *vars);
int			is_c_up_in_b(t_list *pile_b, int c_up);
void		condition_push(t_list **pile_a, t_list **pile_b, int c_up,
				int c_down);
int			pos_last_elemt_to_push(t_list **pile_a);
void		pusher_to_b(t_list **pile_a, t_list **pile_b, t_chunk_level info);
void		push_to_b(t_list **pile_a, t_list **pile_b);
int			is_chunk_in_pile(t_list *pile, int pivot);
void		ft_mover(t_list **pile_a, t_list **pile_b, t_el_to_move elements);
void		sort_process(t_list **pile_a, t_list **pile_b, t_chunk_p *data);
void		sorting_algo(t_list **pile_a, t_list **pile_b, int argc);
void		ft_sort_list(t_list **pile_a, t_list **pile_b, t_var *var);
int			get_cursor_first(t_list *pile_a);
void		fill_direction(t_list **pile_a);
void		finalisation(t_list **pile_a, int argc);
void		ft_sort_three_elt(t_list **pile_a, int argc);
void		sort_medium_list(t_list **pile_a, t_list **pile_b, int argc);
int			pos_last_elemt_to_push(t_list **pile_a);
int			not_to_push(t_list *pile_a, int argc);
void		ft_lstclear(t_list *pile_a, t_list *pile_b);
void		check_is_sort(t_list *pile_a, t_list *pile_b);
void		exec_cmd(char *cmd, t_list **pile_a, t_list **pile_b);
int			check_is_cmd_valide(char *cmd);
void		read_stdin_instruction(t_list **pile_a, t_list **pile_b);
void		free_split(char **list);
int			fill_position(t_list *pile_a);
int			ft_create_list(int argc, char **argv, t_list **pile_a);
int			add_elements_to_list(char **splitted, t_list **pile_a);
int			check_no_overflow(char *str);
int			check_error_input(char *str);

#endif
