#include "main.h"

/**
 * print_int - prints an integer
 * @arg_list: va_list of arguments from _printf
 * @format_flags: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_int(va_list arg_list, flags_t *format_flags)
{
	int number = va_arg(arg_list, int);
	int result = count_digits(number);

	if (format_flags->space == 1 && format_flags->plus == 0 && number >= 0)
		result += _putchar(' ');
	if (format_flags->plus == 1 && number >= 0)
		result += _putchar('+');
	if (number <= 0)
		result++;
	print_number_recursive(number);
	return (result);
}

/**
 * print_unsigned - prints an unsigned integer
 * @arg_list: va_list of arguments from _printf
 * @format_flags: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_unsigned(va_list arg_list, flags_t *format_flags)
{
	unsigned int unsigned_number = va_arg(arg_list, unsigned int);
	char *string = convert(unsigned_number, 10, 0);

	(void)format_flags;
	return (_puts(string));
}

/**
 * print_number_recursive - helper function that recursively
 * prints the digits of an integer
 * @num: integer to be printed
 */
void print_number_recursive(int num)
{
	unsigned int positive_num;

	if (num < 0)
	{
		_putchar('-');
		positive_num = -num;
	}
	else
		positive_num = num;

	if (positive_num / 10)
		print_number_recursive(positive_num / 10);
	_putchar((positive_num % 10) + '0');
}

/**
 * count_digits - returns the number of digits in an integer
 * for _printf
 * @num: integer to evaluate
 * Return: number of digits
 */
int count_digits(int num)
{
	unsigned int digits_count = 0;
	unsigned int positive_num;

	if (num < 0)
		positive_num = -num;
	else
		positive_num = num;

	while (positive_num != 0)
	{
		positive_num /= 10;
		digits_count++;
	}
	return (digits_count);
}
