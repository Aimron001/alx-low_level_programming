#include "main.h"

/**
 * prints numbers except 2 and 4
 *@n: holds the character
 * Return: Always 0.
 */
void print_most_numbers(void)
{
	int n;

	for (n = 48; n < 58; n++)
	{
		if (n != 50)
		{
			if (n != 52)
			{
				_putchar(n);
			}
		}
	}
	_putchar('\n');
}
