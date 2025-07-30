#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
	printf("ft_strlen('Hello, 42!'):\n%zu\n", ft_strlen("Hello, 42!"));

	char *dup = ft_strdup("Hello, 42!");
	printf("ft_strdup('Hello, 42!'): \n%s\n", dup);

	printf("ft_strcmp('Hello, World!', 'Hello ,42!') et ('Hello, 42!', 'Hello, 42!'): \n%d %d\n", ft_strcmp("Hello, World!", "Hello, 42!"), ft_strcmp("Hello, 42!", "Hello, 42!"));
	
	printf("ft_atoi('-131629'): \n%d\n", ft_atoi("-131629"));
	
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
	printf("ft_bzero('Hello, 42!', ft_strlen('Hello, 42!')): \n%s\n", dup);
	
	ft_memmove(itoa + 2, itoa, 2);
	printf("ft_memmove(itoa + 2, itoa, 2): \n%s\n", itoa);
	
	char *buffer3 = "Hello\0World!";
	char *memchr = ft_memchr(buffer3, 'W', 11);
	printf("ft_memchr('Hello/0World!', 'W', 11): \n%s\n", memchr);
	
	int memcmp = ft_memcmp(buffer2, buffer2, sizeof(int) * 10);
	int memcmp2 = ft_memcmp(dup, itoa, 4);
	printf("ft_memcmp(*int, *int) et (str1, str2):\n%d %d\n", memcmp, memcmp2);
	
	printf("ft_isalpha('b') ('2'): \n%d %d\n", ft_isalpha('b'), ft_isalpha('2'));

	printf("ft_isdigit('H') ('4'): \n%d %d\n", ft_isdigit('H'), ft_isdigit('4'));

	printf("ft_isalnum('y') ('9'): \n%d %d\n", ft_isalnum('y'), ft_isalnum('9'));

	printf("ft_isascii(0) (255): \n%d %d\n", ft_isascii(0), ft_isascii(255));

	printf("ft_isprint(0) ('*'): \n%d %d\n", ft_isprint(0), ft_isprint('*'));
	
	char a = ft_toupper('b');
	char b = ft_toupper('5');
	printf("ft_toupper('b') ('5'): \n%c %c\n", a, b);

	printf("ft_tolower('B') ('a'): \n%c %c\n", ft_tolower(a), ft_tolower('a'));

	printf("ft_strchr('Hello', 'l'): \n%s\n", ft_strchr("Hello", 'l'));

	printf("ft_strrchr('Hello', 'l'): \n%s\n", ft_strrchr("Hello", 'l'));

	printf("ft_strncmp('Hello', 'Hellno', 4): \n%d\n", ft_strncmp("Hello", "Hellno", 4));
	printf("ft_strncmp('Hello', 'Hellno', 6): \n%d\n", ft_strncmp("Hello", "hellno", 6));

	free(dup);
	free(buffer2);
	free(itoa);
	return 0;
}
