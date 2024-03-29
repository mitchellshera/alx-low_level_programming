#include "main.h"

/**
 * print_binary - prints the binary representation of a no.
 * @n: parameter
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int curr;

	for (i = 63; i >= 0; i--)
	{
		curr = n >> i;

		if (curr & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
}
