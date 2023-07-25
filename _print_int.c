#include "main.h"
#include <unistd.h>

/**
 * _print_int - print an integer
 * @n: the integer to print
 * Return: the number of characters printed
 */

int _print_int(int n)
{
	int printed_chars = 0;

	if (n < 0)
	{
		printed_chars += _putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
		printed_chars += _print_int(n / 10);

	printed_chars += _putchar('0' + n % 10);

	return (printed_chars);
}
