#include "main.h"
#include <stddef.h>

/**
 * _precision - Extracts the precision value from the format string.
 * @format: The format string containing the conversion specifier.
 * Return: The precision value as an integer, or -1 if not specified.
 */
int _precision(const char *format)
{
	int precision = -1; /* Default precision value is -1, meaning not specified */

	if (format == NULL)
		return (precision);

	/* Check if there is a period (.) in the format string */
	const char *dot = _print_str(format, '.');

	if (dot != NULL)
	{
		/* Extract the precision value as a non-negative integer */
		precision = atoi(dot + 1);
	}

	return (precision);
}
