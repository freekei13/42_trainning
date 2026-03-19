#include "lexing.h"

t_token	*lexer(char *line)
{
	t_token	*tokens;
	int		i;
	int		start;
	char	*word;
	char	*tmp;

	tokens = NULL;
	i = 0;
	start = 0;
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
		{
			//Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon)
		}
	}
	return (tokens);
}