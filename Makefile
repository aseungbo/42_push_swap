# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 14:34:24 by seuan             #+#    #+#              #
#    Updated: 2021/07/20 14:34:25 by seuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = push_swap

CC		= gcc $(CFLAGS)

CLFAGS	= -Wall -Wextra -Werror

SRCS = argv_error_check.c \
		command.c \
		create_stack.c \
		pivot_helper.c \
		push_swap.c \
		sort_elem_all.c \
		sort_elem_five.c \
		sort_elem_three.c \
		sort_elem_two.c \
		sort.c \
		util.c \
		util2.c \
		util3.c \

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -I push_swap.h -o $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re