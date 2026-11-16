NAME = interface
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re