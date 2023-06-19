#include <stdio.h>
#include <stdlib.h>

/**
 * is_number - checks if a string is a valid number
 * @s: string to check
 *
 * Return: 1 if true, 0 if false
 */
int is_number(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * mul - multiplies two numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: result of multiplication
 */
int mul(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * main - entry point
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (!is_number(argv[1]) || !is_number(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = mul(num1, num2);
	printf("%d\n", result);
	return (0);
}

