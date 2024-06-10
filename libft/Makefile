NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
      ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
      ft_memset.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strlcpy.c \
      ft_strlcat.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
      ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c \
      ft_putstr_fd.c ft_putnbr_fd.c ft_split.c ft_substr.c \
      ft_strjoin.c ft_itoa.c ft_strtrim.c ft_strchr.c ft_strmapi.c \
      ft_striteri.c 
BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
      ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
      ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = ${SRC:.c=.o}
OBJB = ${BNS:.c=.o}

LIBC = ar -rcs

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	 ${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJB} ${NAME}
	${LIBC} ${NAME} ${OBJB}

clean:
	${RM} ${OBJS} ${OBJB}

fclean:	clean
	${RM} ${NAME}

re: fclean all bonus

.PHONY: all fclean clean bonus re .c.o
