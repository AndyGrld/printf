#include "main.h"

/**
 * get_print - selects the appropriate printing function
 * based on the conversion specifier passed to _printf
 * @specifier: character that holds the conversion specifier
 * Description: the function loops through the func_array[] to find a match
 * between the specifier passed to _printf and the specifier in the struct,
 * and then returns the appropriate printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char specifier))(va_list, flags_t *)
{
	ph print_function_array[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}};
	int num_functions = 14;

	register int index;

	for (index = 0; index < num_functions; index++)
	{
		if (print_function_array[index].c == specifier)
			return (print_function_array[index].f);
	}
	return (NULL);
}
