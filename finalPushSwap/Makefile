NAME = push_swap

FILES = main.c\
		calculation.c\
		check.c\
		fill.c\
		moves.c\
		utils.c

OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o = ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all