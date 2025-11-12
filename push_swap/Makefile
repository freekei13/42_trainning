# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 11:28:14 by csamakka          #+#    #+#              #
#    Updated: 2025/11/11 11:34:52 by csamakka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = 
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all:$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $^
	
%.o:%.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all