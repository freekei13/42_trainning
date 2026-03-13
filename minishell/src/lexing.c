#include "lexing.h"

t_token	*lexer(char *line)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '|')
		{
			add_token_back(&tokens, new_token(line[i], PIPE));
		}
		else if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				add_token_back(&tokens, new_token(">>", APPEND));
				i++;
			}
			add_token_back(&tokens, new_token(line[i], REDIRECT_OUT));
		}
		else if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				add_token_back(&tokens, new_token("<<", HEREDOC));
				i++;
			}
			add_token_back(&tokens, new_token(line[i], REDIRECT_IN));
		}
		else
			// token WORD
	}
	return (tokens);
}