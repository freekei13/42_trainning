NAME = libft.a

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCLUDES = -Iincludes

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test:
	$(CC) $(CFLAGS) main.c $(INCLUDES) $(NAME) -o test
	./test
	rm test

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
