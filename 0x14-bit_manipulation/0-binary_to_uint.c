#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 * Return: the number that's converted
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dval = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dval = 2 * dval + (b[i] - '0');
	}
	return (dval);
}
