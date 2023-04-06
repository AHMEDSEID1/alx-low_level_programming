#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
  * main - Genrates random password for
  * program: 101-crackme
  * Return: Always 0
  */
int main(void)
{
	int i;
	int password_length = 10;
	char password[password_length + 1];

	srand(time(NULL));
	for (i = 0; i < password_length; i++)
	{
		password[i] = rand() % 94 + 33;
	}
	password[password_length] = '\0';
	printf("Random password: %s\n", password);
	return (0);
}

