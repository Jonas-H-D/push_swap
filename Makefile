# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 13:50:52 by jhermon-          #+#    #+#              #
#    Updated: 2022/03/04 14:41:17 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = list.c utils.c swap.c utils_2.c main.c swap_b.c swap_ab.c atoi.c push.c sort_simple.c sort_algo.c sort_algo_2.c ft_itoa.c

CC = gcc -g

NAME = push_swap

OBJ = $(SRC:.c=.o)
	
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) 
	     $(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
		$(CC) $(FLAGS) -c $(SRC)

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re