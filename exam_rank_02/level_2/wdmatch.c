// Assignment name  : wdmatch
// Expected files   : wdmatch.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and checks whether it's possible to
// write the first string with characters from the second string, while respecting
// the order in which these characters appear in the second string.

// If it's possible, the program displays the string, followed by a \n, otherwise
// it simply displays a \n.

// If the number of arguments is not 2, the program displays a \n.

// Examples:

// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// quarante deux$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int ac, char **av)
{
	char	nl;
	int		i;
	int		j;
	int		match_count;

	nl = '\n';
	if (ac != 3)
		return (write(1, &nl, 1), 0);
	if (ft_strlen(av[1]) > ft_strlen(av[2]))
		return (write(1, &nl, 1), 0);
	i = 0;
	j = 0;
	match_count = 0;
	while (av[1][i])
	{
		if (!av[2][j])
			return (write(1, &nl, 1), 0);
		while (av[2][j])
		{
			if (av[1][i] == av[2][j])
			{
				match_count++;
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (match_count != ft_strlen(av[1]))
		return (write(1, &nl, 1), 0);
	ft_putstr(av[1]);
	write(1, &nl, 1);
}