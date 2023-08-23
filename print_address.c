#include "main.h"

/**
 * print_address - prints address of input in hexadecimal format
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_address(va_list arg_list, flags_t *format_flags)
{
	char *str;
	unsigned long int address = va_arg(arg_list, unsigned long int);

	register int character_count = 0;

	(void)format_flags;

	if (!address)
		return (_puts("(nil)"));
	str = convert(address, 16, 1);
	character_count += _puts("0x");
	character_count += _puts(str);
	return (character_count);
}
