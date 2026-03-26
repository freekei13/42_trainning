#include "lexing.h"

t_token	*lexer(char *line)
{
	t_token	*tokens;
	int		i;
	int		counter;
	int		single_q;
	int		double_q;
	char	*word;

	single_q = 0;
	double_q = 0;
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
			while ((line[counter] != ' ' && line[counter] != '|' && line[counter] != '<' && line[counter] != '>') || (double_q == 1 || single_q == 1))
			{
				if (!line[counter])
					break ;
				if (line[counter] == '\"')
				{
					if (double_q != 0)
						double_q = 0;
					else
						double_q = 1;
				}
				if (line[counter] == '\'')
				{
					if (single_q != 0)
						single_q = 0;
					else
						single_q = 1;
				}
				counter++;
			}
			word = ft_substr(line, i, counter - i);
			add_token_back(&tokens, new_token(word, WORD));
			free(word);
			i = counter;
		}
	}
	return (tokens);
}
