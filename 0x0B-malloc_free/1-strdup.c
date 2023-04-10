#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - check the code
 * @str: argument for array
 * Return: Always 0.
 */
char *_strdup(char *str)
{
	char *my_array;
	int i, len = 0;

	my_array = malloc((len + 1) * sizeof(char));

	i = len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}

	if (my_array == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		my_array[i] = str[i];
		i++;
	}

	return (my_array);
}
