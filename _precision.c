#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _find_period - Finds the position of the period (.) in the string.
 * @str: The input string.
 * Return: A pointer to the position of the period in the string, or NULL if not found.
 */

const char *_find_period(const char *str)
{
if (str == NULL)
return (NULL);

while (*str)
{
if (*str == '.')
return (str);
str++;
}

return (NULL);
}

/**
 * _precision - Extracts the precision value from the format string.
 * @format: The format string containing the conversion specifier.
 * Return: The precision value as an integer, or -1 if not specified.
 */

int _precision(const char *format)
{
int precision = -1; /* Default precision value is -1, meaning not specified */
const char *dot;

if (format == NULL)
return (precision);

/* Find the period (.) in the format string */
dot = _find_period(format);

if (dot != NULL)
{
/* Extract the precision value as a non-negative integer */
precision = atoi(dot + 1);
}

return (precision);
}
