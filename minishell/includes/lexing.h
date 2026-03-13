#ifndef LEXING_H
# define LEXING_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef enum e_type
{
    WORD,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    APPEND,
    HEREDOC,
} 			t_type;

typedef struct	s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
} 					t_token;

#endif