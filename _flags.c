#include "main.h"

/**
 * _flags - Counts active flags
 * @format: Formatted string for args printing
 * @i: takes parameter
 *
 * Return: Flags
 */

int _flags(const char *format, int *i)
{
	int k, current_i;
	int flags = 0;
	const char FLAGS_CHARACTER[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {FlagMinus, FlagPlus, FlagZero,
		FlagHash, FlagSpace, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (k = 0; FLAGS_CHARACTER[k] != '\0'; k++)
			if (format[current_i] == FLAGS_CHARACTER[k])
			{
				flags |= FLAGS_ARRAY[k];
				break;
			}

		if (FLAGS_CHARACTER[k] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}

