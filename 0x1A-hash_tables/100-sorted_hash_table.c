#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Inserts or updates a key/value in the sorted hash table.
 * @ht: The sorted hash table to modify.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *current_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    current_node = ht->array[index];

    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            free(current_node->value);
            current_node->value = strdup(value);
            return (1);
        }
        current_node = current_node->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    shash_table_sorted_insert(ht, new_node);

    return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in the sorted hash table.
 * @ht: The sorted hash table to search in.
 * @key: The key.
 *
 * Return: The value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *current_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
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

/**
 * shash_table_print - Prints the elements of the sorted hash table in order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current_node;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    current_node = ht->shead;
    while (current_node != NULL)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", current_node->key, current_node->value);
        current_node = current_node->snext;
        first = 0;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the elements of the sorted hash table in reverse order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current_node;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    current_node = ht->stail;
    while (current_node != NULL)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", current_node->key, current_node->value);
        current_node = current_node->sprev;
        first = 0;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *current_node, *temp_node;
    unsigned long int i;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current_node = ht->array[i];
        while (current_node != NULL)
        {
            temp_node = current_node;
            current_node = current_node->next;
            free(temp_node->key);
            free(temp_node->value);
            free(temp_node);
        }
    }

    free(ht->array);
    free(ht);
}
