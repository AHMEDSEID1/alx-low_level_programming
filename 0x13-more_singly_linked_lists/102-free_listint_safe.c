#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @head: Double pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t free_listint_safe(listint_t **head)
{
	listint_t *current, *next;
	size_t count = 0;

	if (head == NULL)
		return (0);

	current = *head;
	while (current != NULL)
	{
		count++;
		next = current->next;
		free(current);
		if (next >= current)
		{
			*head = NULL;
			break;
		}
		current = next;
	}

	*head = NULL;

	return (count);
}
