NAME = mapb
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Contact.cpp Phonebook.cpp
OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re