// Assignment name  : lcm
// Expected files   : lcm.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function who takes two unsigned int as parameters and returns the
// computed LCM of those parameters.

// LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
// integer divisible by the both integers.

// A LCM can be calculated in two ways:

// - You can calculate every multiples of each integers until you have a common
// multiple other than 0

// - You can use the HCF (Highest Common Factor) of these two integers and
// calculate as follows:

// 	LCM(x, y) = | x * y | / HCF(x, y)

//   | x * y | means "Absolute value of the product of x by y"

// If at least one integer is null, LCM is equal to 0.

// Your function must be prototyped as follows:

//   unsigned int    lcm(unsigned int a, unsigned int b);

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;

	if (a == 0 || b == 0)
		return (0);
	if (a % b == 0 || b % a == 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < b)
	{
		i = 1;
		while (1)
		{
			if ((b * i) % a == 0)
				return (b * i);
			i++;
		}
	}
	i = 1;
	while (1)
	{
		if ((a * i) % b == 0)
			return (a * i);
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned int	lcm_res;
// 	unsigned int	a;
// 	unsigned int	b;
// 	a = 46;
// 	b = 15;
// 	lcm_res = lcm(a, b);
// 	printf("LCM de %u et %u est %u\n", a, b, lcm_res);
// }