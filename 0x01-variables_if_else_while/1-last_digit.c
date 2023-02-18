#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point - using puts
 *
 *Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	int j = n % 10;

	if ((j) > 5)
	{
		printf("Last digit of %d is %d and is greater than 5", n, j);
	}
	else if (j == 0)
	{
		printf("Last digit of %d is %d and is greater than 0", n, j);
	}
	else
	{
		printf("Last digit of %d is %d and is less than 6 and not 0", n, j);
	}
	return (0);
}
