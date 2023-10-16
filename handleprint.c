#include "main.h"

/**
 * handlePrint - Prints arg based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: args to be printed.
 * @ind: index
 * @buffer: Array handling print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: 1 or 2;
 */

int handlePrint(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_characters = -1;
	fmt_t fmt_types[] = {
		{'c', printChar}, {'s', printString}, {'%', printPercent},
		{'i', printInt}, {'d', printInt}, {'b', printBinary},
		{'u', printUnsigned}, {'o', printOctal}, {'x', printLowerHexa},
		{'X', printUpperHexa}, {'p', printPointer}, {'S', printUnprintable},
		{'r', printReverse}, {'R', printString_rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}
	return (printed_characters);
}

