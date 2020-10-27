#include "holberton.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int contador = 0;
	va_list args;

	print_fx fx[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_i},
		{NULL, NULL}
	};
	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	contador = aux_func(format, args, fx);
	va_end(args);
	return (contador);
}

/**
 * aux_func - auxiliary function
 * @format: format
 * @args: args
 * @fx: fx
 * Return: Always 0
 */
int aux_func(const char *format, va_list args, print_fx *fx)
{
	int contador = 0, flag = 0, i = 0;

	while (*format)
	{
		if (*format == '%')
		{
			while (fx[i].s)
			{
				if (*(format + 1) == '%')
				{
					_putchar(*format);
					contador++;
					format = format + 2;
					flag = 1;
					break;
				}
				else if (*(format + 1) == *fx[i].s)
				{
					contador += fx[i].f(args);
					format = format + 2;
					flag = 1;
					break;
				}
				i++;
			}
			if (flag == 0)
			{
				_putchar(*format);
				_putchar(*(format + 1));
				contador = contador + 2;
				format = format + 2;
			}
		}
		else
		{
			_putchar(*format);
			contador++, format++;
		}
	}
	return (contador);
}
