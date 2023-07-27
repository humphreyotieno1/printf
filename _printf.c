#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int handle_conversion(const char *format, va_list args);
int _precision(const char *format);
int _print_str(char *str);
int _print_int(int n);
int _putchar(char c);

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
			if (*format == '\0') /* Invalid conversion: % at the end of format */
				return (-1);


			printed_chars += handle_conversion(format, args);
			format++;
		}
		else
		{
			printed_chars += _putchar(*format);
			/*printed_chars++; */
			format++;
		}
	}

	va_end(args);

	return (printed_chars);
}

/**
 * handle_conversion - Handles the conversion specifier in the format string.
 * @format: Pointer to the conversion specifier character.
 * @args: The va_list of arguments.
 * Return: The number of characters printed for this conversion.
 */
int handle_conversion(const char *format, va_list args)
{
	int printed_chars = 0;

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
		case 'b':
			{
				unsigned int num = va_arg(args, unsigned int);

				char binary[33];

				printf(binary, sizeof(binary), "%u", num);
				printed_chars += _print_str(binary);
				break;
			}
		default:
			printed_chars += _putchar('%');
			printed_chars += _putchar(*format);
			/*printed_chars += 2; */
			break;
	}
	return (printed_chars);
}
