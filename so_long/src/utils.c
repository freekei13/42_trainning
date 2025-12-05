#include "so_long.h"

void	free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_tablen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}