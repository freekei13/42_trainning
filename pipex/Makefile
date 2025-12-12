NAME = pipex
SRC = pipex.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS =
RM = rm -f

LIB = ./libft/libft.a
LIB_P = ./libft

PRINT = ./ft_printf/libftprintf.a
PRINT_P = ./ft_printf

all: $(NAME)

$(NAME):$(OBJ) $(LIB) $(PRINT)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.c pipex.h
	$(CC) $(FLAGS) -c $< -o $@

$(LIB):
	@make -C $(LIB_P)

$(PRINT):
	@make -C $(PRINT_P)

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIB_P)
	@make clean -C $(PRINT_P)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIB_P)
	@make fclean -C $(PRINT_P)

re: fclean all