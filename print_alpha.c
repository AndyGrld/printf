#include "main.h"

/**
 * print_string - loops through a string and prints
 * every character
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_string(va_list arg_list, flags_t *format_flags)
{
	char *string = va_arg(arg_list, char *);

	(void)format_flags;

	if (!string)
		string = "(null)";
	return (_puts(string));
}

/**
 * print_char - prints a character
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_char(va_list arg_list, flags_t *format_flags)
{
	(void)format_flags;
	_putchar(va_arg(arg_list, int));
	return (1);
}
