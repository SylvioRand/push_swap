NAME = libftprintf.a

SRC = ft_strlen.c ft_printf.c ft_print_adress.c ft_putchar.c ft_putnbr_i.c ft_putnbr_x.c ft_putnbr_u.c ft_putstr.c ft_print_value.c

SRC_BONUS = ft_strlen.c ft_printf_bonus.c ft_print_adress.c ft_print_adress_bonus.c ft_putchar.c ft_putnbr_i.c ft_putnbr_i_bonus.c ft_putnbr_x.c ft_putnbr_x_bonus.c ft_putnbr_u.c ft_putstr.c ft_initializer.c ft_utils.c ft_get_len_initial_value.c ft_print_condition_diu.c ft_print_value.c ft_functions_printer.c ft_format_diu.c ft_format_c.c  ft_format_x.c ft_format_s.c ft_format_p.c

OBJS = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

LIBC = ar -rcs

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	

all: ${NAME}

bonus: dellib ${OBJ_BONUS}
	${LIBC} ${NAME} ${OBJ_BONUS}

clean:
	rm -rf ${OBJS} ${OBJ_BONUS}

fclean: clean
	rm -rf ${NAME}

dellib :
	rm -rf libftprintf.a

re : fclean all

.PHONY: all fclean clean re .c.o 
