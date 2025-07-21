#include "../includes/libft.h"

int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int	sign;
	int	len;
	char	*str;
	char	*res;
	int	i;
	int	j;

	len = ft_intlen(nb);
	sign = 0;
	if (nb < 0)
	{
		sign = sign + 1;
		nb = nb * -1;
	}
	str = malloc(sizeof(char) * (sign + len + 1));
	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (sign + len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (nb != 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	str[i] = '\0';
	j = 0;
	if (sign == 1)
	{
		res[j] = '-';
		j++;
	}
	while ( i > 0)
	{
		res[j] = str[i - 1];
		j++;
		i--;
	}	
	res[j] = '\0';
	free(str);
	return (res);
}
