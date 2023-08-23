#include <stdio.h>
#include <stdarg.h>

int handle_format(const char *format, va_list *args, int *count)
{
	format++;			   // Skip the '%'
	int format_length = 2; // Start with 2 because '%' plus the specifier character

	switch (*format)
	{
	case 'c':
	{
		char ch = va_arg(*args, int);
		putchar(ch);
		(*count)++;
		break;
	}
	case 's':
	{
		char *str = va_arg(*args, char *);
		while (*str != '\0')
		{
			putchar(*str);
			str++;
			(*count)++;
		}
		break;
	}
	case '%':
	{
		putchar('%');
		(*count)++;
		break;
	}
	default:
		format_length = 1; // Set back to 1 if no specifier was handled
		break;
	}

	return format_length;
}

int _printf(const char *format, ...)
{
	va_list all_args;
	va_start(all_args, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			int format_length = handle_format(format, &all_args, &count);
			format += format_length;
		}
		else
		{
			putchar(*format);
			count++;
			format++;
		}
	}

	va_end(all_args);

	return count;
}

int main(void)
{
	int printed = _printf("Hello, %s! The answer is %d%c.\n", "Alice", 42, '%');
	printf("\nCharacters printed: %d\n", printed);

	printed = _printf("Let's print a %c and a %s.\n", 'Z', "string");
	printf("\nCharacters printed: %d\n", printed);

	return 0;
}
