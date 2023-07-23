#include "main.h"

/**
 * _print_str - Prints a string to the standard output.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */

int _print_str(char *str)
{
	int i, count = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		count++;
	}

	return (count);
}
