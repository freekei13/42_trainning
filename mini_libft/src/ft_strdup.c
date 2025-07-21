#include "../includes/mini_libft.h"

char	*ft_strdup(const char *str)
{
	int	i;
	char	*str_dup;

	str_dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str_dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_dup[i] = str[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}
	
