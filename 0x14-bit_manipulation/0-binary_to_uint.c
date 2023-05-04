#include "main.h"
/**
 * binary_to_uint - converts binary number to an unsigned int
 * @b: pointer to a string containing 0 and 1s
 * Return: the converted decimal number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int int_val = 0;

	if (b == 0)
		return (0);
	i = 0;
	while (b[i])
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		int_val = 2 * int_val + (b[i] - '0');
	}

	return (int_val);
}
