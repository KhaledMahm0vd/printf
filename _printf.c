#include "main.h"

void printing_buffer(char buffer[], int *buffer_index);

/**
* _printf - formatted output printing to standard output.
* @format: input string containing specifiers.
*
* Return: number of characters printed which does not include null byte.
*/
int _printf(const char *format, ...)
{
	signed int i = 0, printed = 0, printed_characters = 0;
	int flags, width, precision, size;
	int buffer_index = 0;
	va_list arguments;
	char buffer[BUFFER_SIZE];

	if (format == NULL) {
		return (-1);
	}

	va_start(arguments, format);

	for (i = 0; format && format[i] != '\0'; i++) {
		if (format[i] != '%') {
			if (buffer_index == BUFFER_SIZE) {
				printing_buffer(buffer, &buffer_index);
			}

			if (buffer_index < BUFFER_SIZE) {
				buffer[buffer_index++] = format[i];
			}
			printed_characters++;
		} else {
			printing_buffer(buffer, &buffer_index);
			flags = _flags(format, &i);
			width = _width(format, &i, arguments);
			precision = _precision(format, &i, arguments);
			size = _size(format, &i);
			i++;
			printed = handlePrint(format, &i, arguments, buffer,
				flags, width, precision, size);
			if (printed == -1) {
			}
			printed_characters += printed;
		}
	}

	printing_buffer(buffer, &buffer_index);

	va_end(arguments);

	return (printed_characters);
}

void printing_buffer(char buffer[], int *buffer_index)
{
	if (buffer == NULL) {
		return;
	}

	if (*buffer_index > 0) {
		write(1, &buffer[0], *buffer_index);
	}

	*buffer_index = 0;
}

