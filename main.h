#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 1024

int _putchar(char c);

/* Function to print a string */
int _print_str(char *str);

/* Function to implement the _printf function */
int _printf(const char *format, ...);

/*Function to print an integer*/
int _print_int(int n);

#endif
