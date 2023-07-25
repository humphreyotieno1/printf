#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_str - Prints a string.
 * @str: The string to be printed.
 * Return: The number of characters printed.
 */
int _print_str(char *str)
{

	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		printed_chars++;
		str++;
	}

	return (printed_chars);
}
