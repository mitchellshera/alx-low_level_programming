#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at the given index of a dlistint_t linked list.
 * @head: Double pointer to the head of the doubly linked list.
 * @index: Index of the node to be deleted, starting from 0.
 *
 * Return: 1 if deletion succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
        return -1;

    dlistint_t *current = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return 1;
    }

    unsigned int count = 0;
    while (count < index)
    {
        if (current == NULL)
            return -1;
        current = current->next;
        count++;
    }

    if (current == NULL)
        return -1;

    current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    free(current);

    return 1;
}
