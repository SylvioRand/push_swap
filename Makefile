NAME = push_swap
BONUS_NAME = checker

SRC = main.c ft_isdigit.c ft_atol.c ft_lstadd_back.c \
	  ft_lstnew.c ft_lstlast.c push_functions.c \
	  swap_functions.c rotate_functions.c reverse_functions.c \
	  cost_functions.c utils.c movers_functions.c \
	  cost_getters.c ft_is_number.c selector.c \
	  updater.c sorter_functions.c pusher_to_pile_b.c \
	  sort_utils.c medium_sort.c extra_pusher_functions.c \
	  ft_lstclear.c cleanup_memory.c data_processing_func.c

SRC_BONUS = checker.c ft_is_number.c ft_isdigit.c \
			ft_atol.c ft_lstnew.c ft_lstadd_back.c \
			ft_lstlast.c push_checker_func.c \
			swap_checker_func.c rotate_checker_func.c \
			reverse_checker_func.c \
			./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c ft_lstclear.c \
			checker_utils.c cleanup_memory.c data_processing_func.c

OBJS = ${SRC:.c=.o}

OBJS_BONUS = ${SRC_BONUS:.c=.o}

FT_PRINTF_PATH = ./ft_printf
LIBFT_PATH = ./libft
GNL_PATH = ./get_next_line

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C $(FT_PRINTF_PATH) bonus
	$(MAKE) -C $(LIBFT_PATH) all
	${CC} ${CFLAGS} ${OBJS} $(FT_PRINTF_PATH)/libftprintf.a $(LIBFT_PATH)/libft.a -o ${NAME}  

bonus : ${BONUS_NAME}

${BONUS_NAME}: ${OBJS_BONUS}
	$(MAKE) -C $(FT_PRINTF_PATH) bonus
	$(MAKE) -C $(LIBFT_PATH) all
	${CC} ${CFLAGS} ${OBJS_BONUS} $(FT_PRINTF_PATH)/libftprintf.a $(LIBFT_PATH)/libft.a -o ${BONUS_NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}
	$(MAKE) -C ${FT_PRINTF_PATH} clean
	$(MAKE) -C ${LIBFT_PATH} clean

fclean:
	${RM} ${OBJS} ${OBJS_BONUS} ${BONUS_NAME} ${NAME}
	$(MAKE) -C ${FT_PRINTF_PATH} fclean
	$(MAKE) -C ${LIBFT_PATH} fclean

re: fclean all

.PHONY: .c.o all clean fclean re
