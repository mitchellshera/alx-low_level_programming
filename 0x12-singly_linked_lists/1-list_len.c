#include "lists.h"

/**
 * list_len - function that returns the number of elements in a linked list_t
 * list.
 * @h: singly linked list
 * Return: number of elements in a linked list_t list.
 */

size_t list_len(const list_t *h)
{
	const list_t *tmp;
	unsigned int i;

	tmp = h;
	for (i = 0; tmp; i++)
		tmp = tmp->next;
	return (i);
}
