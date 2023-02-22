#include "main.h"

#include "main.h"

/**
 * print_alphabet_x10 - prints  the alphabet in lowercase 10 times
 * followed by a new line
 */

void print_alphabet_x10(void)
{
	char letter;
	int num = 0;

	while (num < 10)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
		_putchar('\n');
		num++;
	}
}
