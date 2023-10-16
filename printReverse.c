#include "main.h"

int printReverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, tally = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		tally++;
	}
	return (tally);
}

