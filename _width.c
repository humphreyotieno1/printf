#include "main.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * _width - Extracts the width value from the format string.
 * @format: The format string containing the conversion specifier.
 * @has_precision: A boolean indicating if the format string has a precision.
 * Return: The width value as an integer, or -1 if not specified.
 */

int _width(const char *format, bool has_precision)
{
int width = -1; /* Default width value is -1, meaning not specified */
const char *current = format;

if (format == NULL)
return (width);

/* Check if there is a digit in the format string */
while (*current)
{
if (*current >= '0' && *current <= '9')
{
width = atoi(current);
break;
}
current++;
}

/* If the format string has a precision, and width is specified, reset width to -1 */
if (has_precision && width >= 0)
{
width = -1;
}
return (width);
}
