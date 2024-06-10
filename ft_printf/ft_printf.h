/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:31:30 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 07:39:30 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *str);
int		ft_putchar(char nb);
int		ft_putnbr_i(int nb, int value);
int		ft_putnbr_u(unsigned int nb, int value);
void	ft_print_adress(long unsigned int ptr, int ***value);
void	ft_putnbr_x(unsigned int nbr, char *base, int ***value);
void	print_value(char f, va_list arg, int **value);

#endif
