#include <unistd.h>
#include "main.h"
/**
 *_putchar - prints character a
 * return 1 (success) | -1 on error
 */
int _putchar(char a)
{
	return (write(1, &a, 1));
}
