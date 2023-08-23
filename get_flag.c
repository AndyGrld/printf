#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @flag_char: character that holds the flag specifier
 * @flags_ptr: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char flag_char, flags_t *flags_ptr)
{
	int flag_updated = 0;

	switch (flag_char)
	{
	case '+':
		flags_ptr->plus = 1;
		flag_updated = 1;
		break;
	case ' ':
		flags_ptr->space = 1;
		flag_updated = 1;
		break;
	case '#':
		flags_ptr->hash = 1;
		flag_updated = 1;
		break;
	}

	return (flag_updated);
}
