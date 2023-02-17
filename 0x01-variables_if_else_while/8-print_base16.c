#include <stdio.h>

/**
* main - Print the numbers of base 16 in lowercase
*
* Return: Always 0 (Success)
*/
int main(void)
{
		char dig;

		for (dig = '0'; dig <= '9'; dig++)
		putchar(dig);

		for (dig = 'a'; dig <= 'f'; dig++)
		putchar(dig);

		putchar('\n');

	return (0);
}
