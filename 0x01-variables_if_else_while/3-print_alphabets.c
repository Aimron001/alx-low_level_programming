#include <stdio.h>
/**
 * main - prints the alphabet in lowercase, and then in uppercase
 *
 *Return: Always 0 (Success)
 */
int main(void)
{
	int ch = 'a';
	int CH = 'A';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
        while (CH <= 'Z')
        {
                putchar(CH);
                CH++;
        }
	putchar('\n');
	return (0);
