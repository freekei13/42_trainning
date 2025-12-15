NAME = pipex
SRC = src/pipex.c src/utils.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

LIB = ./libft/libft.a
LIB_P = ./libft

all: $(NAME)

$(NAME):$(OBJ) $(LIB) $(PRINT)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.c pipex.h
	$(CC) $(FLAGS) -c $< -o $@

$(LIB):
	@make -C $(LIB_P)

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIB_P)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIB_P)

re: fclean all