# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emanana <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/26 18:14:14 by emanana           #+#    #+#              #
#    Updated: 2019/08/19 10:02:00 by emanana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME1 = checker

NAME2 = push_swap

SRC1 = checker.c main.c instructions.c stack.c stack2.c tools.c tools2.c checks.c checks2.c print.c

SRC2 = push_swap.c prepare_stacks.c sort_stack_a.c sort_stack_b.c main.c instructions.c \
				stack.c stack2.c tools.c tools2.c checks.c checks2.c print.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

pre:
	@make -C libft
	@make -C libft/get_next_line

$(NAME1): $(OBJ1) pre	
	@$(CC) $(CFLAGS) $(OBJ1) -Llibft -lft \
		-Llibft/get_next_line -lftget_next_line -o $@

$(NAME2): $(OBJ2) pre
	@$(CC) $(CFLAGS) $(OBJ2) -Llibft -lft \
		-Llibft/get_next_line -lftget_next_line -o $@

clean:
	@make clean -C libft
	@make clean -C libft/get_next_line
	@rm -f *.o

fclean:
	@make fclean -C libft
	@make fclean -C libft/get_next_line
	@rm -f *.o
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
