#include "main.h"

/**
 * printPointer - Prints the value of a pointer variable
 * @types: args list
 * @buffer: Array handling print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Numb of chars printed.
 */

int printPointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFFER_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrss;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrss = (unsigned long)address;

	while (num_addrss > 0)
	{
		buffer[ind--] = map_to[num_addrss % 16];
		num_addrss /= 16;
		length++;
	}

	if ((flags & FlagZero) && !(flags & FlagMinus))
		padd = '0';
	if (flags & FlagPlus)
		extra_c = '+', length++;
	else if (flags & FlagSpace)
		extra_c = ' ', length++;

	ind++;

	return (writePointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

