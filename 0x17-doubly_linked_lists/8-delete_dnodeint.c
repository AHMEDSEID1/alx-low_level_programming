#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t
 * @head: Double pointer the head of the linked list
 * @index: Index node to be deleted (starting from 0)
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)  /* Check if head or list is empty */
		return (-1);

	dlistint_t *current = *head;
	unsigned int pos = 0;

	if (index == 0)  /* If index is 0, delete the first node */
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (pos < index && current != NULL)
	{
		current = current->next;
		pos++;
	}

	if (current == NULL)  /* If end of list is reached before index, return -1 */
		return (-1);

	current->prev->next = current->next;  /* Link previous node to next node */

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);  /* Free memory of the deleted node */
	return (1);
}
