#include "variadic_functions.h"
<<<<<<< Updated upstream
#include <stdio.h>
=======
>>>>>>> Stashed changes
#include <stdarg.h>

/**
* sum_them_all - returns sum of all its parameters.
* @n: amount of the arguments.
* Return: sum of its parameters.
*/
int sum_them_all(const unsigned int n, ...)
{
	va_list valist;
	int sum = 0;
	unsigned int i;

	if (n == 0)
		return (0);
		
	va_start(valist, n);
	
	for (i = 0; i < n; i+++)
		sum += va_arg(valist, int);
		
	va_end(valist);
	 
	return (sum);
}
