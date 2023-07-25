#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string containing conversion specifiers.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			switch (*format)

			{
			case 'c':
				printed_chars += _putchar(va_arg(args, int));
				break;
			case 's':
				{
					char *str = va_arg(args, char *);
					if (str == NULL)
					str = "(null)";
					printed_chars += _print_str(str);
					break;
				}
			case '%':
				printed_chars += _putchar('%');
				break;
			case 'd':
			case 'i':
				printed_chars += _print_int(va_arg(args, int));
				break;
			default:
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
				break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (printed_chars);
}

