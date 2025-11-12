# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 11:28:14 by csamakka          #+#    #+#              #
#    Updated: 2025/11/12 14:20:00 by csamakka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = src/push.c src/reverse_rotate.c src/rotate.c src/swap.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

PRINT_PATH = ft_printf/
PRINT_NAME = ft_printf/libftprintf.a
LIBFT_PATH = libft/
LIBFT_NAME = libft/libft.a

GREEN	= \033[38;5;76m
RESET	= \033[00m

all:$(NAME) $(PRINT_NAME) $(LIBFT_NAME)
	
%.o:%.c
	@printf "\n $(GREEN) Compiling... \n$(RESET)"
	$(CC) $(FLAGS) -c $< -o $@

$(PRINT_NAME):
	@make -C $(PRINT_PATH)

$(LIBFT_NAME):
	@make bonus -C $(LIBFT_PATH)

$(NAME):$(OBJ) $(PRINT_NAME) $(LIBFT_NAME) 
	$(AR) $@ $^
	@printf "\n $(GREEN)*** push_swap is ready *** \n $(RESET)"

clean:
	@make clean -C $(PRINT_PATH)
	@make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)
	
fclean: clean
	@make fclean -C $(PRINT_PATH)
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	
re: fclean all