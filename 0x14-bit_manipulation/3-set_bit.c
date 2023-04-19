#include "main.h"
/**
 * set_bit - sets a bit to 1 at a given index
 * @n: pointer to the value to be changed
 * @index: index of the bit to be set to 1
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}

