#include "../includes/mini_libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char	*ch;

	ch = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*ch = (unsigned char)c;
		ch++;
		i++;
	}
	return (ch);
}
