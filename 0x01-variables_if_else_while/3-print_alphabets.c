#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char w = 'a', u = 'A';

	for (; w <= 'z'; w++)
		putchar(w);
	for (; u <= 'Z'; u++)
		putchar(u);
	putchar('\n');
	return (0);
}
