#include "main.h"
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: variable holding the binary number
 * Return: the converted binary number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int unDecNum = 0;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		unDecNum = 2 * unDecNum + (b[i] - '0');
	}
	return (unDecNum);
}
