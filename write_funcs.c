#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @character: The character to print
 * Return: On success 1.
 */
int _putchar(char character)
{
	static char buffer[1024];
	static int index;

	if (character == -1 || index >= 1024)
	{
		write(1, &buffer, index);
		index = 0;
	}
	if (character != -1)
	{
		buffer[index] = character;
		index++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 * @string: pointer to the string to print
 * Return: number of characters written
 */
int _puts(char *string)
{
	register int i;

	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);
	return (i);
}
