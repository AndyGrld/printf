#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - displays output of statement
 * @format: format string with the characters
 * Return: length of output string
 */
int _printf(const char *format, ...)
{
	int (*print_func)(va_list, flags_t *);
	const char *format_ptr;
	va_list args;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (format_ptr = format; *format_ptr; format_ptr++)
	{
		if (*format_ptr == '%')
		{
			format_ptr++;
			if (*format_ptr == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*format_ptr, &flags))
				format_ptr++;
			print_func = get_print(*format_ptr);
			count += (print_func)
						 ? print_func(args, &flags)
						 : printf("%%%c", *format_ptr);
		}
		else
			count += _putchar(*format_ptr);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
