#include "main.h"

/**
 * _size - Calculates size to cas args
 * @format: Formatted string
 * @x: args list to be printed.
 *
 * Return: Size
 */

int _size(const char *format, int *x)
{
	int current_i = *x + 1;
	int size = 0;

	if (format[current_i] == 'l')
		size = STRING_LONG;
	else if (format[current_i] == 'h')
		size = STRING_SHORT;

	if (size == 0)
		*x = current_i - 1;
	else
		*x = current_i;

	return (size);
}

