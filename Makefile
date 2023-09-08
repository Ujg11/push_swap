# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 15:32:29 by ojimenez          #+#    #+#              #
#    Updated: 2023/09/08 15:54:29 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJECTS = main.o errors.o init_stack.o push_swap.o push.o reverse_rotate.o rotate.o sort_for_three.o stack_utils.o swap.o sort_for_five.o

all: $(NAME)

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -s -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -s -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: re all clean fclean
