#include "main.h"
#include <stdio.h>
/**
* main - check the code 
 * @a: an array of integers
 * @n: the number of elements to swap
 *
 * Return: nothing.
 */
void array(int *a, int n)
{
	int i, temp;
	for (i = 0; i < n/2; i++)
	{
		temp = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = temp;
	}
}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	printf("Original array: ");
	for (i = 0; i < n; i++)
        printf("%d ", a[i]);
	printf("\n");
	reverse_array(a, n);

	printf("Reversed array: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

