#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Delete the first element of a singly linked list.
 * @head: Pointer to a list.
 * Return: Integer if success.
 **/

int pop_listint(listint_t **head)
{
	listint_t *p;
	int my_data;

	if (*head == NULL)
		return (0);

	p = *head;
	*head = p->next;
	my_data = p->n;
	free(p);
	return (my_data);
}
