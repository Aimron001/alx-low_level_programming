#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number to be converted
 */
void print_binary(unsigned long int n)
{
	int i, j = 0;
	unsigned long int byte;

	if (n == 0)
	{
		putchar('0');
		return;
	}
	for (i = 63; i >= 0; i--)
	{
		byte = n >> i;
		if (byte & 1)
		{
			_putchar('1');
			j++;
		}
		else
		{
			if (j > 0 || i == 0)
			{
				_putchar('0');
			}
		}
	}
	if (j == 0)
	{
		_putchar('0');
	}
}
