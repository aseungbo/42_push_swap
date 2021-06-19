SRCS = argv_error_check.c \
		command.c \
		create_stack.c \
		pivot_helper.c \
		push_swap.c \
		sort.c \
		util.c \
		sort_under_three.c

OBJS = ${SRCS:.c=.o}

all: ${OBJS}
	${CC} -o push_swap ${OBJS}

.c.o:
	gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re