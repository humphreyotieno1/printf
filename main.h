#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);

/* Function to print a string */
int _print_str(char *str);

/* Function to implement the _printf function */
int _printf(const char *format, ...);

#endif
