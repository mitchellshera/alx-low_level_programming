#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Print elements of a singly linked list.
 * @h: Pointer to a list.
 * Return: Integer.
 **/

size_t print_listint(const listint_t *h)
{
	const listint_t *p;
	unsigned int count = 0;

	p = h;
	while (p)
	{
		printf("%d\n", tp->n);
		count++;
		p = p->next;
	}
	return (count);
}
