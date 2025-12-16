NAME = pipex
SRC = src/pipex.c src/utils.c
SRC_BONUS = src_bonus/pipex_bonus.c src_bonus/utils_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

LIB = ./libft/libft.a
LIB_P = ./libft

all: $(NAME)

$(NAME):$(OBJ) $(LIB)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB):
	@make -C $(LIB_P)
bonus: $(OBJ_BONUS) $(LIB)
	$(CC) $(FLAGS) $^ -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	@make clean -C $(LIB_P)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIB_P)

re: fclean all