#include "main.h"
/**
 * print_binary - converts the binary equivalent of a decimal number
 * @n: number to be converted
 */
void print_binary(unsigned long int n)
{
	int i, j = 0;
	unsigned long int byte;

	for (i = 63; i >= 0; i--)
	{
		byte = n >> i;

		if (byte & 1)
		{
			_putchar('1');
			j++;
		}
		else if (j)
			_putchar('0');
	}
	if (j > 0)
		_putchar('0');
}
