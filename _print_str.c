#include "main.h"
#include <unistd.h>

/**
 * _print_str - Prints a string.
 * @str: The string to be printed.
 * Return: The number of characters printed.
 */

int _print_str(char *str)
{

int len = 0;

if (str == NULL)
str = "(null)";

while (str[len] != '\0')
 len++;

return (write(1, str, len));
}
