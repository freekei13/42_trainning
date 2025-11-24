# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: freekei <freekei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 11:28:14 by csamakka          #+#    #+#              #
#    Updated: 2025/11/25 00:33:05 by freekei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = src/push_swap.c src/reverse_rotate.c src/rotate.c src/swap.c \
	src/push.c src/main.c src/input_check.c src/parse_input.c \
	src/small_sort.c src/ft_free.c
	
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

PRINT_PATH = ft_printf/
PRINT_NAME = ft_printf/libftprintf.a
LIBFT_PATH = libft/
LIBFT_NAME = libft/libft.a

GREEN = \033[38;5;76m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[00m
MAKEFLAGS += -s

all:$(NAME) $(PRINT_NAME) $(LIBFT_NAME)

$(PRINT_NAME):
	@make -C $(PRINT_PATH)
	@printf "$(GREEN)\nft_printf compiled\n$(RESET)"

$(LIBFT_NAME):
	@make bonus -C $(LIBFT_PATH)
	@printf "$(GREEN)\nlibft compiled$(RESET)"

%.o:%.c
	$(CC) -g $(FLAGS) -c $< -o $@
	@printf "$(BLUE)$< -> $@\n$(RESET)"
	
$(NAME):$(OBJ) $(PRINT_NAME) $(LIBFT_NAME)
	$(CC) $(FLAGS) -g $^ -o $(NAME) 
	@printf "$(GREEN)\npush_swap is ready$(RESET)"

clean:
	@make clean -C $(PRINT_PATH)
	@make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)
	@printf "$(RED)$(OBJ) deleted\n$(RESET)"
	
fclean: clean
	@make fclean -C $(PRINT_PATH)
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	@printf "$(RED)$(NAME) deleted\n$(RESET)"
	
re: fclean all