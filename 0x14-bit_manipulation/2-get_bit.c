#include "main.h"
/**
 * get_bit -  returns the value of a bit at a given index
 * @n: given number
 * @index: the index of the bit
 * Return: value of the bit at the given index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);
	bit_val = (n >> index) & 1;
	return (bit_value);
}
