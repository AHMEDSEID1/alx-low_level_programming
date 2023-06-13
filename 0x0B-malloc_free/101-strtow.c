#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * count_words - counts the number of words in a string
 * @str: pointer to the string
 * Return: number of words
 */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (*str == ' ')
			in_word = 0;
		else
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		str++;
	}
	return (count);
}

/**
 * word_len - returns the length of a word
 * @str: pointer to the word
 * Return: length of the word
 */
int word_len(char *str)
{
	int len = 0;

	while (*str && *str != ' ')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * strtow - splits a string into words
 * @str: pointer to the string
 * Return: pointer to an array of words or NULL if failure
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k;
	int num_words, len;

	if (str == NULL || *str == '\0')
		return (NULL);
	num_words = count_words(str);
	words = malloc(sizeof(char *) * (num_words + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < num_words)
	{
		while (str[j] == ' ')
			j++;
		len = word_len(str + j);
		words[i] = malloc(sizeof(char) * (len + 1));
		if (words[i] == NULL)
		{
			while (i--)
				free(words[i]);
			free(words);
			return (NULL);
		}
		k = 0;
		while (k < len)
		{
			words[i][k] = str[j];
			k++;
			j++;
		}
		words[i][k] = '\0';
		i++;
	}
	words[i] = NULL;
	return (words);
}

