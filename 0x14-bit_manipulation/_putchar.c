#include "main.h"
#include <unistd.h>
/**
 * _putchar – prints a character c to stdout
 * @c: This is the character to be output
 * Return: always 1 on success.
 * 		 -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

