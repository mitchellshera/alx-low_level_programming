#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strlen - finds the length of the string
 * @str: the string
 * Return: length of string
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: double pointer to a linked list
 * @str: string to add to the new node
 *
 * Return: pointer to the new node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode, *tmp;

	if (str == NULL)
		return (NULL);
	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	newnode->str = strdup(str);
	if (newnode->str == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->len = _strlen(newnode->str);
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newnode;
	return (newnode);
}
