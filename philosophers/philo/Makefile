NAME	= 	philo
CC		= 	gcc
CFLAGS	= 	-Werror -Wall -Wextra -pthread

SRC_PATH = src/
OBJ_PATH = obj/

SRC		=	main.c \
			parsing.c \
			utils.c \
			simulation.c \
			checks.c

SRCS	= 	$(addprefix $(SRC_PATH), $(SRC))
OBJ 	= 	$(SRC:.c=.o)
OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))
INC 	= 	-I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re