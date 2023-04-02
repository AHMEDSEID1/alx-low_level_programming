#include <stdio.h>

/**
 * main - print first 98 Fibonacci numbers
 *
 * Return: 0
 */
int main(void)
{
	int counter;

	unsigned long a = 1;
	unsigned long b = 2;
	unsigned long sum = 0;

	printf("%lu", a);
	for (counter = 0; counter < 97; counter++)
	{
		printf(", %lu", b);
		sum = a + b;
		a = b;
		b = sum;
	}
	printf("\n");
	return (0);
}

