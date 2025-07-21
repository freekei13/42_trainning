#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
	printf("ft_strlen: %zu\n", ft_strlen("Hello, 42!"));
	printf("ft_strdup: %s\n", ft_strdup("Hello, 42!"));
	printf("ft_strcmp: %d %d\n", ft_strcmp("Hello, World!", "Hello, 42!"), ft_strcmp("Hello, 42!", "Hello, 42!"));
	printf("ft_atoi: %d\n", ft_atoi("       ---++---131629kdiHdf"));
	char buffer[10];
	ft_memset(buffer, '*', 10);
	printf("ft_memset: %s\n", buffer);
	int *buffer2 = ft_calloc(10, sizeof(int));
	printf("ft_calloc:");
	for (int i = 0; i < 10; i++)
		printf(" %d", buffer2[i]);
	printf("\n");
	char *itoa = ft_itoa(1303);
	printf("ft_itoa: %s\n", itoa);
	free(itoa);
	free(buffer2);
	return 0;
}
