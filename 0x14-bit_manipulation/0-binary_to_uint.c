#include <stdlib.h>
#include "main.h"

/** 
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of characters representing a binary number
 *
 * Return: the converted binary number, or 0 if an error occurs
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int num = 0;
    if (b == NULL)
    {
        return 0; // if b is NULL, return 0
    }
    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] == '0')
        {
            num = num << 1; // shift left and add 0
        }
        else if (b[i] == '1')
        {
            num = (num << 1) | 1; // shift left and add 1
        }
        else
        {
            return 0; // if b contains a non-binary character, return 0
        }
    }
    return num;
}
