#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int handle_conversion(const char *format, va_list args);
int _precision(const char *format);
int _print_str(char *str);
int _print_int(int n);
int _putchar(char c);
int _print_ptr(void *ptr);
int _print_uint(unsigned int n);
int _print_oct(unsigned int n);
int _print_hex(unsigned int n, int uppercase);
int _print_str_non_printable(char *str);

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
			case 'u':
			printed_chars += _print_uint(va_arg(args, unsigned int));
			break;
			case 'o':
			printed_chars += _print_oct(va_arg(args, unsigned int));
			break;
			case 'x':
			printed_chars += _print_hex(va_arg(args, unsigned int), 0);
			break;
			case 'X':
			printed_chars += _print_hex(va_arg(args, unsigned int), 1);
			break;
			case 'S':
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				printed_chars += _print_str_non_printable(str);
				break;
			}
			case 'p':
			printed_chars += _print_ptr(va_arg(args, void *));
		case 'b':
			{
				unsigned int num = va_arg(args, unsigned int);

				char binary[33];

				for (int i = 31; i >= 0; i--)
				{
					binary[31 - i] = ((num >> i) & 1) + '0';
				}
				binary[32] = '\0';

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
/*
 * main - implementations of the functions
 * Return: 0
 */

int main(void)
{
	unsigned int num = 42;

	char *non_printable_str = "Hello, \nWorld!\t";

	int *ptr = &num;

	_printf("Unsigned Decimal: %u\n", num);
	_printf("Octal: %o\n", num);
	_printf("Lowercase Hex: %x\n", num);
	_printf("Uppercase Hex: %X\n", num);
	_printf("Octal String: %S\n", non_printable_str);
	_printf("Pointer Address: %p\n", ptr);
	_printf("Binary representation: %b\n", num);
	return (0);
}
