#include "main.h"
/**
 * get_bit - returns the value of a bit at an index
 * @n: the number to be searched
 * @index: index of the bit
 * Return: value of a bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bitVal;

	if (index > 63)
		return (-1);
	bitVal = (n >> index) & 1;
	return (bitVal);
}
