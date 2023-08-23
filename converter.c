#include "main.h"

/**
 * convert - converts number and base into string
 * @number: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int number, int base, int lowercase)
{
	static char *representation;
	static char buffer[50];
	char *pointer;

	representation = (lowercase)
						 ? "0123456789abcdef"
						 : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';
	do {
		*--pointer = representation[number % base];
		number /= base;
	} while (number != 0);

	return (pointer);
}
