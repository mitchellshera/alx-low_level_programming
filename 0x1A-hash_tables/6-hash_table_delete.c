#include "hash_tables.h"
/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *current_node;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current_node = ht->array[i];
        free_hash_list(current_node);
    }

    free(ht->array);
    free(ht);
}

/**
 * free_hash_list - Frees a linked list of hash_node_t nodes.
 * @head: The head of the linked list.
 */
void free_hash_list(hash_node_t *head)
{
    hash_node_t *current;
    hash_node_t *next;

    current = head;

    while (current != NULL)
    {
        next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
}
