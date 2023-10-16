#include "main.h"

/**
 * printLowerHexa - Prints unsigned number in Lower hexadecimal notation
 * @types: args lidt
 * @buffer: Array handling print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int printLowerHexa(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printHexadecimal(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

