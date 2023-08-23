#include "main.h"

/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (uppercase - always 2 characters)
 * @arg_list: va_list arguments from _printf
 * @format_flags: determines if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_bigS(va_list arg_list, flags_t *format_flags)
{
	int i, character_count = 0;
	char *result;
	char *string = va_arg(arg_list, char *);

	(void)format_flags;

	if (!string)
		return (_puts("(null)"));

	for (i = 0; string[i]; i++)
	{
		if (string[i] > 0 && (string[i] < 32 || string[i] >= 127))
		{
			_puts("\\x");
			character_count += 2;
			result = convert(string[i], 16, 0);
			if (!result[1])
				character_count += _putchar('0');
			character_count += _puts(result);
		}
		else
			character_count += _putchar(string[i]);
	}
	return (character_count);
}

/**
 * print_rev - prints a string in reverse
 * @arg_list: argument from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list arg_list, flags_t *format_flags)
{
	int i = 0, j;
	char *string = va_arg(arg_list, char *);

	(void)format_flags;

	if (!string)
		string = "(null)";

	while (string[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(string[j]);

	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @arg_list: list of arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rot13(va_list arg_list, flags_t *format_flags)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *string = va_arg(arg_list, char *);

	(void)format_flags;

	for (j = 0; string[j]; j++)
	{
		if (string[j] < 'A' || (string[j] > 'Z' && string[j] < 'a')
				|| string[j] > 'z')
			_putchar(string[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (string[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_percent - prints a percent
 * @arg_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags in which we turn the flags on
 * Return: number of characters printed
 */
int print_percent(va_list arg_list, flags_t *format_flags)
{
	(void)arg_list;
	(void)format_flags;
	return (_putchar('%'));
}
