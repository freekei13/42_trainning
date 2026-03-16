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
			if (line[i] == '\"')
			{
				start = i + 1;
				while (line[i + 1] != '\"')
					i++;
				if (!line[i])
				{
					while(1)
					{
						tmp = get_next_line(0);
					}
				}
				add_token_back(&tokens, new_token(ft_substr(line, start, i - start + 1)), WORD);
			}

		}
	}
	return (tokens);
}