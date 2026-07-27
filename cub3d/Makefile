NAME = cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror

MAIN_PATH = main/

SRC_MAIN = main.c

SRCS = $(addprefix $(MAIN_PATH), $(SRC_MAIN))

OBJ = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I ./include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re