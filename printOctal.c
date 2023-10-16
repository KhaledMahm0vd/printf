#include "main.h"

/**
 * printOctal - Prints unsigned number in octal notation
 * @types: args list
 * @buffer: Array handling print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int printOctal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
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
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FlagHash && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (writeUnsigned(0, i, buffer, flags, width, precision, size));
}

