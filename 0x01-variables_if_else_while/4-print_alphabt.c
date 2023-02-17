#include <stdio.h>

/**
* main - Print the alphabet in lowercase letters, except for e and q
*
* Return: Always 0 (Success)
*/
int main(void)
{
		char ch;

		for (ch = 'a'; ch <= 'z'; ch++)
		{
		if (ch != 'e' && ch != 'q')
		putchar(ch);
		}
		putchar('\n');

		return (0);
}
