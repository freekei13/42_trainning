# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 13:17:42 by freekei           #+#    #+#              #
#    Updated: 2025/10/21 11:09:30 by csamakka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_print_chars.c ft_print_dec.c ft_print_hex_p.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all:$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $^
	
%.o:%.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all