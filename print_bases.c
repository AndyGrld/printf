#include "main.h"

/**
 * print_hex - prints a number in hexadecimal base,
 * in lowercase
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turn converts the input
 * number into the correct base and returns it as a string
 * Return: the number of characters printed
 */
int print_hex(va_list arg_list, flags_t *format_flags)
{
	unsigned int number = va_arg(arg_list, unsigned int);
	char *string = convert(number, 16, 1);
	int character_count = 0;

	if (format_flags->hash == 1 && string[0] != '0')
		character_count += _puts("0x");
	character_count += _puts(string);
	return (character_count);
}

/**
 * print_hex_big - prints a number in hexadecimal base,
 * in uppercase
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turn converts the input
 * number into the correct base and returns it as a string
 * Return: the number of characters printed
 */
int print_hex_big(va_list arg_list, flags_t *format_flags)
{
	unsigned int number = va_arg(arg_list, unsigned int);
	char *string = convert(number, 16, 0);
	int character_count = 0;

	if (format_flags->hash == 1 && string[0] != '0')
		character_count += _puts("0X");
	character_count += _puts(string);
	return (character_count);
}

/**
 * print_binary - prints a number in base 2
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turn converts the input
 * number into the correct base and returns it as a string
 * Return: the number of characters printed
 */
int print_binary(va_list arg_list, flags_t *format_flags)
{
	unsigned int number = va_arg(arg_list, unsigned int);
	char *string = convert(number, 2, 0);

	(void)format_flags;
	return (_puts(string));
}

/**
 * print_octal - prints a number in base 8
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turn converts the input
 * number into the correct base and returns it as a string
 * Return: the number of characters printed
 */
int print_octal(va_list arg_list, flags_t *format_flags)
{
	unsigned int number = va_arg(arg_list, unsigned int);
	char *string = convert(number, 8, 0);
	int character_count = 0;

	if (format_flags->hash == 1 && string[0] != '0')
		character_count += _putchar('0');
	character_count += _puts(string);
	return (character_count);
}
