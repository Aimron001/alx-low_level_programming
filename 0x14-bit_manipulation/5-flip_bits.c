#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * @n: first number
 * @m: second number
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, num_bits = 0;
	unsigned long int curr;
	unsigned long int exclusive_num = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		curr = exclusive_num >> i;
		if (curr & 1)
			num_bits++;
	}
	return (num_bits);
}

