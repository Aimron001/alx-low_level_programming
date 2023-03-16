#include <stdlib.h>
#include "main.h"
/**
 * *malloc_checked - allocates memory using malloc
 * @n: number of bytes to allocate
 * Return: a pointer to the allocated memory
 */
void *malloc_checked(unsigned int n)
{
	void *ptr;

	ptr = malloc(n);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}
