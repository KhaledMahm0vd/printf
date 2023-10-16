#include "main.h"

/**
 * printability - Evaluates char printability
 * @c: Character to be evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int printability(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appnd_hex_code - Append ASCII in hex to buffer.
 * @buffer: Array of characters
 * @i: Appending start index
 * @ac: ASSCI CODE
 * Append hexadecimal code of the given ASCII character to buffer
 * at given index. Returns the number of characters appended.
 * Ensure that the ASCII code is positive.
 * Append the hexadecimal code to the buffer.
 *
 * Return: Always 3
 */

int appnd_hex_code(char ac, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ac < 0)
		ac *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ac / 16];
	buffer[i] = map_to[ac % 16];

	return (3);
}

/**
 * is_digit - verifies if char is digit
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * conv_sz_num - casts a number to predefined size
 * @num: Num to be casted.
 * @size: type to be casted.
 *
 * Return: Casted value of num
 */

long int conv_sz_num(long int num, int size)
{
	if (size == STRING_LONG)
		return (num);
	else if (size == STRING_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_sz_unsigned - Casts a number to predefined size
 * @num: Num to be casted
 * @size: type to be casted to
 *
 * Return: Casted value of num
 */

long int conv_sz_unsigned(unsigned long int num, int size)
{
	if (size == STRING_LONG)
		return (num);
	else if (size == STRING_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

