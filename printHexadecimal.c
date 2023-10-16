#include "main.h"

/**
 * printHexadecimal - Prints a hexadecimal number in lower or uppercase
 * @types: args list
 * @map_to: Array of values to map the number to
 * @buffer: Array handling print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int printHexadecimal(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = conv_sz_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FlagHash && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (writeUnsigned(0, i, buffer, flags, width, precision, size));
}

