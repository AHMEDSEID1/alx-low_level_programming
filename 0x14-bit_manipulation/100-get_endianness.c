#include "main.h"
#include <stdio.h>
/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *p = (char *)&x;

	return ((int)*p);
}

