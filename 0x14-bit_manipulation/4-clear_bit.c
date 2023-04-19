#include "main.h"
/**
 * clear_bit - sets the value of a given bit to 0 at a given index
 * @n: pointer to the number to be changed
 * @index: index of the bit to change
 * Return: 1 on success, -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
