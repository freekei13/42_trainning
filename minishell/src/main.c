#include "lexing.h"

int	main(void)
{
	char *cmd;
	t_token *tokens;
	while (1)
	{
		cmd = readline("minishell $");
		if (!cmd)
			break ;
		add_history(cmd);
		tokens = lexer(cmd);
		free(cmd);
		while (tokens != NULL)
		{
			printf("Value : %s\nType : %d\n\n", tokens->value, tokens->type);
			tokens = tokens->next;
		}
	}
	return (0);
}