# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamakka <csamakka@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 14:17:23 by csamakka          #+#    #+#              #
#    Updated: 2025/09/30 15:53:06 by csamakka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

CC = cc

all: $(NAME)

$(NAME):$(OBJ) 
	ar rcs $@ $^
%.o: %.c libft.h
	$(CC) -Wall -Wextra -Werror -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
