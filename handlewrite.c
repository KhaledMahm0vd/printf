#include "main.h"

/**
 * handleWriteChar - Prints a string
 * @c: char types.
 * @buffer: Array handling print
 * @flags:  Evaluates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int handleWriteChar(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FlagZero)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = padd;

		if (flags & FlagMinus)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * writeNumber - Prints a string
 * @is_negative: args list
 * @ind: char types.
 * @buffer: Array handling print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int writeNumber(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & FlagZero) && !(flags & FlagMinus))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & FlagPlus)
		extra_ch = '+';
	else if (flags & FlagSpace)
		extra_ch = ' ';

	return (writeNum(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * writeNum - Writes numbers using bufffer
 * @ind: index number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @prec: Precision
 * @length: Num length
 * @padd: Padding char
 * @extra_c: Extra char
 *
 * Return: Num of chars printed.
 */

int writeNum(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FlagMinus && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & FlagMinus) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FlagMinus) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * writeunsigned - Writes an unsigned number
 * @is_negative: indicates if num is negative
 * @ind: index number starts on the buffer
 * @buffer: Array of characters
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Num of chars printed.
 */

int writeUnsigned(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & FlagZero) && !(flags & FlagMinus))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & FlagMinus)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * writePointer - Writes a memory address
 * @buffer: Arrays of characters
 * @ind: index number starts in the buffer
 * @length: Num length
 * @width: Width
 * @flags: Flags
 * @padd: Represents padding
 * @extra_c: Character representing extra char
 * @padd_start: index padding should start
 *
 * Return: Num of chars printed.
 */

int writePointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FlagMinus && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & FlagMinus) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FlagMinus) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}

