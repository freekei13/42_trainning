#include "lexing.h"

t_token	*new_token(char *value, int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->type = type;
	token->next = NULL;
	return (token);
}

void	add_token_back(t_token **lst, t_token *new)
{
	t_token *current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while(current->next != NULL)
		current = current->next;
	current->next = new;
}

void	free_tokens(t_token *lst)
{
	t_token *current;
	t_token *next;

	current = lst;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}
