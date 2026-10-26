NAME = zombie
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re