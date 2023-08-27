#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of itself
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	unsigned int num_bytes, i;
	unsigned char *address = (unsigned char *)main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < num_bytes; i++)
	{
		unsigned char opcode = *(unsigned char *)address;

		printf("%02x", opcode);

		if (i != num_bytes - 1)
			printf(" ");
		address++;
	}

	printf("\n");

	return (0);
}
