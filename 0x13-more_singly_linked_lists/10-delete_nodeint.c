#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index
 * @head: pointer
 * @idx: index of node to delete
 *
 * Return: 1 on succes
 */
int delete_nodeint_at_index(listint_t **head, unsigned int idx)
{
	listint_t *current, *previous;
	unsigned int k;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (idx == 0)
	{
		*head = current->next;
		free(current);
		return (1);

	}

	previous = NULL;
	for (k = 0; k < idx; k++)
	{
		if (current == NULL)
			return (-1);

		previous = current;
		current = current->next;
	}

	if (previous != NULL)
		previous->next = current->next;
	else
		*head = current->next;

	free(current);

	return (1);
}
