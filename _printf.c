#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list all_args;
	va_start(all_args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == "%")
		{
			format++;
		}
		count++;
		format++;
	}
	vprintf(format, all_args);
	va_end(all_args);
}
