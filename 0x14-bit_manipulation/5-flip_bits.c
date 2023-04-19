#include "main.h"

/**
 * flip_bits - counts the number of bits to be flipped
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, j = 0;
	unsigned long int curr_bit;
	unsigned long int ex_bit = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		curr_bit = ex_bit >> i;
		if (curr_bit & 1)
		{
			j++;
		}
	}
	return (j);
}

