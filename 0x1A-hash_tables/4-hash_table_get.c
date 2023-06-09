#include "hash_tables.h"
/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table to look into.
 * @key: The key being searched for.
 *
 * Return: The value associated with the key if found, NULL otherwise.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *current_node;
    unsigned long int index;

    if (ht == NULL)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    current_node = ht->array[index];

    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
            return (current_node->value);

        current_node = current_node->next;
    }

    return (NULL);
}
