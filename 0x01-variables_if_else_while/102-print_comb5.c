#include <stdio.h>

/**
 * main - prints all possible combinations of two two-digit numbers
 * Return: 0
 */
int main(void)
{
	int num1, num2;

	for (num1 = 0; num1 <= 99; num1++)
	{
		for (num2 = 0; num2 <= 99; num2++)
		{
		int num1_d1 = num1 / 10;
		int num1_d2 = num1 % 10;
		int num2_d1 = num2 / 10;
		int num2_d2 = num2 % 10;

		if (num1 != num2)
		{
			putchar(num1_d1 + '0');
			putchar(num1_d2 + '0');
			putchar(' ');
			putchar(num2_d1 + '0');
			putchar(num2_d2 + '0');

			if (num1 != 99 || num2 != 98)
			{
				putchar(',');
				putchar(' ');
			}
		}
		}
	}

	putchar('\n');
	return (0);
}
