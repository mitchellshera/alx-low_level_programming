#include "hash_tables.h"

/**
 * key_index - Returns the index of a key in a hash table array.
 * @key: The key string.
 * @size: The size of the array of the hash table.
 *
 * Return: The index at which the key/value pair should be stored,
 *         based on the hash value of the key and the array size.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key) % size;

	return (index);
}
