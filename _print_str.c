#include "main.h"
#include <unistd.h>

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
printed_chars += _putchar(*str);
str++;
}

return (printed_chars);
}
