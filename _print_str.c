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
	int len = 0;
if (str == NULL)
{

write(1, "(null)", 6);
return (6);
}


while (str[len] != '\0')
len++;

return (write(1, str, len));
}
