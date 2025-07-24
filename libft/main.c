#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
	printf("ft_strlen(Hello, 42!):\n%zu\n", ft_strlen("Hello, 42!"));

	char *dup = ft_strdup("Hello, 42!");
	printf("ft_strdup(Hello, 42!): \n%s\n", dup);

	printf("ft_strcmp(Hello, World!, Hello ,42!) et (Hello, 42!, Hello, 42!): \n%d %d\n", ft_strcmp("Hello, World!", "Hello, 42!"), ft_strcmp("Hello, 42!", "Hello, 42!"));
	
	printf("ft_atoi(-131629): \n%d\n", ft_atoi("-131629"));
	
	char buffer[10];
	ft_memset(buffer, '*', 10);
	printf("ft_memset(buffer, '*', 10): \n%s\n", buffer);
	
	int *buffer2 = ft_calloc(10, sizeof(int));
	printf("ft_calloc(10, sizeof(int)):\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", buffer2[i]);
	printf("\n");
	
	char *itoa = ft_itoa(1303);
	printf("ft_itoa(1303): \n%s\n", itoa);
	
	ft_memcpy(buffer, itoa, 4);
	printf("ft_memcpy(buffer, itoa, 4): \n%s\n", buffer);
	
	ft_bzero(dup, ft_strlen(dup));
	printf("ft_bzero(Hello, 42!, ft_strlen(Hello, 42!)): \n%s\n", dup);
	
	ft_memmove(itoa + 2, itoa, 2);
	printf("ft_memmove(itoa + 2, itoa, 2): \n%s\n", itoa);
	
	char *buffer3 = "Hello\0World!";
	char *memchr = ft_memchr(buffer3, 'W', 11);
	printf("ft_memchr(Hello World!, 'W', 11): \n%s\n", memchr);
	
	free(dup);
	free(buffer2);
	free(itoa);
	return 0;
}
