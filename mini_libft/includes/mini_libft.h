#ifndef MINI_LIBFT_H
#define MINI_LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);

#endif
