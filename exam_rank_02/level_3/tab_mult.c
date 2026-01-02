// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>

#include <unistd.h>
#include <limits.h>

int	ft_atoi_p(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putnbr_p(int num)
{
	char	n_print;

	if (num > 9)
	{
		ft_putnbr_p(num / 10);
		ft_putnbr_p(num % 10);
	}
	else
	{
		n_print = num + 48;
		write(1, &n_print, 1);
	} 
}
int	main(int ac, char **av)
{
	char	nl;
	int		i;
	int		num;
	int		count;

	nl = '\n';
	if (ac != 2)
		return (write(1, &nl, 1), 0);
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
			return (write(1, &nl, 1), 0);
		i++; 
	}
	num = ft_atoi_p(av[1]);
	if (num > INT_MAX / 9)
		return (write(1, &nl, 1), 0);
	count = 9;
	i = 0;
	while (i < count)
	{
		ft_putnbr_p(i + 1);
		ft_putstr(" x ");
		ft_putnbr_p(num);
		ft_putstr(" = ");
		ft_putnbr_p(num * (i + 1));
		ft_putstr("\n");
		i++;
	}
}
