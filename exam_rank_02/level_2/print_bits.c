// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	res[8];

	i = 8;
	while (i)
	{
		res[i - 1] = octet % 2 + 48;
		octet = octet / 2;
		i--;
	}
	while (res[i])
		write(1, &res[i++], 1);
}

// int main(void)
// {
// 	unsigned char octet = 254;
// 	print_bits(octet);
// }