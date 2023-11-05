#include "search_algos.h"

/**
 * binary_search - function that searches for a value
 * using the Binary search algorithm
 *
 * @array: pointer to the of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for in the array
 *
 * Return: The first index where value is located
 * or -1 not found or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	size_t middle = 0;
	size_t i = 0;

	if (array != NULL)
	{
		while (left <= right)
		{
			middle = (left + right) / 2;
			printf("Searching in array: ");
			for (i = left; i < right; i++)
			{
				printf("%d, ", array[i]);
			}
			printf("%d\n", array[i]);
			if (array[middle] < value)
			{
				left = middle + 1;
			}
			else if (array[middle] > value)
			{
				right = middle - 1;
			}
			else
			{
				return (middle);
			}
		}
	}
	return (-1);
}
