#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
