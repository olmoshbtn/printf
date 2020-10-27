#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct format_func - struct to choose the right function depending on the
 * format specifier passed to _printf()
 * @s: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct format_func
{
	char *s;
	int (*f)();
} print_fx;

/* _putchar */
int _putchar(char c);

/* _printf */
int _printf(const char *format, ...);

/* print characters */
int print_c(va_list args);

/* print strings */
int print_s(va_list args);

/* print integers */
int print_i(va_list args);

/* auxiliary function */
int aux_func(const char *format, va_list args, print_fx *fx);
#endif
