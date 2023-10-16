#include "main.h"

/**
 * printUnprintable - Prints ASCII CODE in hexa for unprintable chars
 * @types: args list
 * @buffer: Array handling print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int printUnprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (printability(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += appnd_hex_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

