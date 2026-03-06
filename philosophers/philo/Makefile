NAME	= 	philo
CC		= 	cc
CFLAGS	= 	-Werror -Wall -Wextra -pthread

SRC_PATH = src/
OBJ_PATH = obj/

SRC		=	main.c \
			parsing.c \
			utils.c \
			simulation.c \
			checks.c \
			routine_actions_a.c \
			routine_actions_b.c \
			reaper_actions.c \
			cleaners.c

SRCS	= 	$(addprefix $(SRC_PATH), $(SRC))
OBJ 	= 	$(SRC:.c=.o)
OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))
INC 	= 	-I ./includes/

GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
RESET   = \033[0m

all: $(NAME)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@CURRENT=$$(( $$(ls $(OBJ_PATH)*.o 2>/dev/null | wc -l) + 1)); \
	TOTAL=$(words $(SRC)); \
	FILLED=$$(printf '%.0s██' $$(seq 1 $$CURRENT)); \
	DOT=$$(( $$CURRENT % 3 )); \
	REMAINDER=$$(( $$TOTAL - $$CURRENT )); \
	if [ $$DOT -eq 1 ]; then \
		MSG="Compiling."; \
	elif [ $$DOT -eq 2 ]; then \
		MSG="Compiling.."; \
	else \
		MSG="Compiling..."; \
	fi; \
	if [ $$REMAINDER -gt 0 ]; then \
    	EMPTY=$$(printf '%.0s░░' $$(seq 1 $$REMAINDER)); \
	else \
    	EMPTY=""; \
	fi; \
	printf "\r[$$FILLED$$EMPTY] $(GREEN)%-30s$(RESET)" "$$MSG"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@CURRENT=$(words $(SRC)); \
	printf "\r[$(BLUE)$$(printf '%.0s██' $$(seq 1 $$CURRENT))$(RESET)] $(GREEN)Compiling...Done!$(RESET)%-20s\n" ""
	@$(CC) $(CFLAGS) $^ -o $@
	@echo ""
	@echo "✅ $(NAME) compiled successfully!✅"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "🗑️  Objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️  $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re