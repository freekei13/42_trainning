# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: freekei <freekei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 00:13:10 by csamakka          #+#    #+#              #
#    Updated: 2025/12/03 03:10:28 by freekei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = src/main.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wextra -Werror
RM = rm -f

all:$(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

mlx:
	@make -C ./mlx_linux
	
$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 

clean:
	@make clean -C ./mlx_linux
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: mlx clean fclean re