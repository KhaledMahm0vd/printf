#include "main.h"

/**
 * printUpperHexa - Prints unsigned number in Upper hexadecimal notation
 * @types: args list
 * @buffer: Array handling print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int printUpperHexa(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printHexadecimal(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

