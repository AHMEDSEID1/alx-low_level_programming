#include <stdio.h>
/**
 * main - printing numbers from 0-9 with commas and space between them
 *
 * Description: using main function
 *  this program prints "0, 1, 2, 3, 4, 5, 6, 7, 8, 9"
 * Return: 0
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
		for (j = i + 1; j < 10; j++)
		{
		putchar(i + '0');
		putchar(j + '0');
		if (i == 8 && j == 9)
		{
			break;
		}
			putchar(',');
			putchar(' ');
	}
	putchar('\n');
	return (0);
}
