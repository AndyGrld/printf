#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list all_args;
	va_start(all_args, format);
	vprintf(format, all_args);
	va_end(all_args);
}

int main(void)
{
	_printf("Hello, %s, i am %d", "World", 19);
	return (0);
}
