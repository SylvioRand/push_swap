/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:10:02 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 11:47:01 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_data
{
	int				nb_int;
	unsigned int	nb_uint;
	unsigned long	nb_uint_ptr;
	char			*str;
}			t_data;

typedef struct s_flag_check
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	number;
	int	width;
	int	hashtag;
	int	point;
}		t_flags;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *str);
int		ft_putchar(char nb);
int		ft_putnbr_i(int nb, int value);
int		ft_putnbr_u(unsigned int nb, int value);
void	ft_print_adress(long unsigned int ptr, int ***value);
void	ft_putnbr_x(unsigned int nbr, char *base, int ***value);
void	ft_print_adress_bonus(long unsigned int ptr);
int		ft_putnbr_i_bonus(int nb, int value);
void	ft_putnbr_x_bonus(unsigned int nbr, char *base);
void	init_status(t_flags *status);
void	init_list(t_data *list);
int		check_f_presence(char c, char *format_list);
int		format_pos(char *flags);
void	fill_flags(char *format, char *flags, int format_p);
int		ft_abs(int value);
int		nb_digit(long value, char f);
int		nb_char_x(unsigned int value);
int		nb_char_p(unsigned long int value);
void	len_for_pos_value(t_flags *status, int nb_dgt, int *len_to_print);
int		def_len_to_print(t_flags *status, int nb_dgt, t_data *lst, char f);
void	print_condition_di(t_flags *status, t_data *lst, char f, int **len);
void	print_condition_u(t_flags *status, t_data *lst, char f, int **len);
void	print_value(char f, va_list arg, int **value);
void	print_value_flags(char f, t_data *list);
int		write_zero(int nb);
int		write_space(int nb);
void	write_sign(t_flags *status, t_data *lst, int *nb_dgt, int **len);
void	justify_left_du(t_flags *status, t_data *lst, char f, int *len);
void	justify_right_du(t_flags *status, t_data *lst, char f, int *len);
void	zero_flags_diu(t_flags *status, t_data *lst, char f, int *len);
void	ft_print_diu(t_flags *status, t_data *list, char f, int ****value);
void	justify_right_c(t_flags *status, t_data *lst, int *length);
void	justify_left_c(t_flags *status, t_data *lst, int *length);
void	ft_print_c(t_flags *status, t_data *list, int ****value);
void	null_case_right_s(t_flags *status, int **length);
void	justify_right_s(t_flags *status, t_data *lst, int *length);
void	null_case_left_s(t_flags *status, int **length);
void	justify_left_s(t_flags *status, char f, t_data *lst, int *length);
void	ft_print_s(t_flags *status, char f, t_data *list, int ****value);
void	justify_right_x(t_flags *status, t_data *lst, char f, int *len);
void	justify_left_x(t_flags *status, t_data *list, char f, int *length);
void	zero_flags_x(t_flags *status, t_data *lst, char f, int *len);
void	ft_print_x(t_flags *status, char f, t_data *list, int ****value);
void	justify_right_p(t_flags *status, t_data *lst, char f, int *len);
void	justify_left_p(t_flags *status, t_data *list, char f, int *length);
void	zero_flags_p(t_flags *status, t_data *lst, char f, int *len);
void	ft_print_p(t_flags *status, char f, t_data *list, int ****value);

#endif
