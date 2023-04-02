#include <stdio.h>
/**
 * main - prints if the number is postive,zero, or negative
 *
 * Description: using main function
 * this program prints "Programming is positive, zero, or negative
 *Return: 0
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
	putchar(i + '0');
	}
	for (i = 'a'; i <= 'f'; i++)
	{
	putchar(i);
	}
	putchar('\n');
	return (0);
}
