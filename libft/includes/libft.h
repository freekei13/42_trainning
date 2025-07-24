#ifndef MINI_LIBFT_H
#define MINI_LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int nb);
int	ft_intlen(int nb);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);

#endif
