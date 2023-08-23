#include <stdio.h>
#include "main.h"

void flush_buffer(char buffer[], int *buffer_index);

/**
 * _printf - printf function
 * @format: Format string
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int i, chars_printed = 0, total_printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args_list;
	char output_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			output_buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				flush_buffer(output_buffer, &buffer_index);
			chars_printed++;
		}
		else
		{
			flush_buffer(output_buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args_list);
			precision = get_precision(format, &i, args_list);
			size = get_size(format, &i);
			++i;
			chars_printed = handle_format(format, &i, args_list, output_buffer,
										  flags, width, precision, size);
			if (chars_printed == -1)
				return (-1);
			total_printed_chars += chars_printed;
		}
	}

	flush_buffer(output_buffer, &buffer_index);

	va_end(args_list);

	return (total_printed_chars);
}

/**
 * flush_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buffer_index: index to add next character
 */
void flush_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
