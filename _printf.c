#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _print_char - Prints a single character.
 * @c: The character to be printed.
 * Return: The number of characters printed (1 if successful, 0 if failed).
 */
int _print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_str - Prints a string.
 * @str: The string to be printed.
 * Return: The number of characters printed (excluding the null byte).
 */
int _print_str(const char *str)
{
	if (str == NULL)
	str = "(null)";
	return (write(1, str, _strlen(str)));
}

/**
 * _print_int - Prints an integer.
 * @num: The integer to be printed.
 * Return: The number of characters printed.
 */
int _print_int(int num)
{
	int n_chars = 0;
	int is_negative = 0;

	if (num == 0)
	{
		return (_print_char('0'));
	}
	else if (num < 0)
	{
		is_negative = 1;
		num = -num;
		n_chars += _print_char('-');
	}

	int reversed = 0;

	while (num != 0)
	{
		reversed = reversed * 10 + (num % 10);
		num /= 10;
	}

	while (reversed != 0)
	{
		n_chars += _print_char(reversed % 10 + '0');
		reversed /= 10;
	}

	return (n_chars + is_negative);
}

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
					printed_chars += _print_char(va_arg(args, int));
					break;
				case 's':
					{
						char *str = va_arg(args, char *);

						printed_chars += _print_str(str);
						break;
					}
				case '%':
					printed_chars += _print_char('%');
					break;
				case 'd':
				case 'i':
					printed_chars += _print_int(va_arg(args, int));
					break;
				default:
					printed_chars += _print_char('%');
					printed_chars += _print_char(*format);
					break;
			}
		}
		else
		{
			printed_chars += _print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
