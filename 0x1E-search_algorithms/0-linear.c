#include "main.h"

/**
 * linear_search - Function that searches for a value in an
 * array of integers
 * @array: Array is a pointer to the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for in the array
 *
 * Return: The first index where value is located
 * or -1 if not found or if array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			if (array[i] == value)
			{
				return (i);
			}
		}
	}
	return (-1);
}
