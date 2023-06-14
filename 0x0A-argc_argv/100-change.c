#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 if successful, 1 otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	int cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	int coins = 0;

	int denominations[] = {25, 10, 5, 2, 1};
	int size = sizeof(denominations) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		coins += cents / denominations[i];
		cents %= denominations[i];
	}

	printf("%d\n", coins);
	return (0);
}

