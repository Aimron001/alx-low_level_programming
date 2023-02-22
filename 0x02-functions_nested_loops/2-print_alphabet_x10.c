#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase followed by a new linex10
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
