#include "lexing.h"

t_token	*lexer(char *line)
{
	t_token	*tokens;
	int		i;
	int		counter;
	char	*word;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '|')
		{
			add_token_back(&tokens, new_token("|", PIPE));
			i++;
		}
		else if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				add_token_back(&tokens, new_token(">>", APPEND));
				i += 2;
			}
			else
			{
				add_token_back(&tokens, new_token(">", REDIRECT_OUT));
				i++;
			}
		}
		else if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				add_token_back(&tokens, new_token("<<", HEREDOC));
				i += 2;
			}
			else
			{
				add_token_back(&tokens, new_token("<", REDIRECT_IN));
				i++;
			}
		}
		else
		{
			counter = i;
			if (line[i] == '\"')
			{
				counter++;
				while (line[counter] != '\"' && line[counter])
				{
					counter++;
				}
				word = ft_substr(line, i, counter + 1 - i);
				add_token_back(&tokens, new_token(word, WORD));
				i = counter + 1;
			}
			else if (line[i] == '\'')
			{
				counter++;
				while (line[counter] != '\'' && line[counter])
				{
					counter++;
				}
				word = ft_substr(line, i, counter + 1 - i);
				add_token_back(&tokens, new_token(word, WORD));
				i = counter + 1;
			}
			else
			{
				while (line[counter] != ' ' && line[counter] != '|' && line[counter] != '>' && line[counter] != '<' && line[counter])
				{
					counter++;
				}
				word = ft_substr(line, i, counter - i);
				add_token_back(&tokens, new_token(word, WORD));
				i = counter;
			}
		}
	}
	return (tokens);
}
