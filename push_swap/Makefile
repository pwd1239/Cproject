NAME = push_swap

FILES = push.c\
		pushswap.c\
		get.c\
		radixSort.c\
		revRotate.c\
		rotate.c\
		sort.c\
		swap.c\
		utils.c\
		util2.c

OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o = ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	$(CC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all