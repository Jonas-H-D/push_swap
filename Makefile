# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 13:50:52 by jhermon-          #+#    #+#              #
#    Updated: 2022/03/04 15:55:50 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = list.c\
				utils.c\
				swap.c\
				utils_2.c\
				main.c\
				swap_b.c\
				swap_ab.c\
				atoi.c\
				push.c\
				sort_simple.c\
				sort_algo.c\
				sort_algo_2.c\
				ft_itoa.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

OBJS_DIR = ./objs
INC_DIR = .
LIBFT_DIR	= ./libft
LIBFT = libft.a

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)


$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) -I$(LIBFT_DIR) -c $^

clean: 
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re