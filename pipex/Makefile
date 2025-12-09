NAME = pipex
SRC = pipex.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

LIB = ./libft/libft.a
LIB_P = ./libft

PRINT = ./ft_printf/libftprintf.a
PRINT_P = ./ft_printf

all: $(NAME)

$(NAME):$(OBJ) $(LIB) $(PRINT)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.c pipex.h
	$(CC) $(FLAGS) $< -o $@

$(LIB):
	@make -C $(LIB_P)

$(PRINT):
	@make -C $(PRINT_P)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all