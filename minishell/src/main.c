#include "lexing.h"

int	main(void)
{
	char *cmd;

	while (1)
	{
		cmd = readline("minishell $");
		if (!cmd)
			break ;
		add_history(cmd);
		free(cmd);
	}
	return (0);
}