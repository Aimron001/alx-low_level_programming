#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number tobe converted to  binary
 */
void print_binary(unsigned long int n)
{
	int i, j = 0;
	unsigned long int b_num;

	for (i = 63; i >= 0; i--)
	{
		b_num = n >> i;

		if (b_num & 1)
		{
			_putchar('1');
			j++;
		}
		else if (j)
			_putchar('0');
	}
	if (!j)
		_putchar('0');
}
