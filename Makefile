# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 15:42:39 by seuan             #+#    #+#              #
#    Updated: 2021/06/21 16:09:45 by seuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC		= gcc $(CFLAGS) $(leaks) 

RM		= rm -rf

CLFAGS	= -Wall -Wextra -Werror

leaks = -g3 -fsanitize=address

SRCS	= argv_error_check.c \
			command.c \
			create_stack.c \
			pivot_helper.c \
			push_swap.c \
			sort.c \
			util.c \
			sort_under_three.c

OBJS 	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -I push_swap.h -o $(NAME)

all : $(NAME)

clean :
		$(RM) ./*.o

fclean : clean
		$(RM) $(NAME)

re : fclean clean all

.PHONY : all fclean clean re