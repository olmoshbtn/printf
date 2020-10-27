#include "holberton.h"
/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int  i;
	int contador = 0;
	va_list args;
	print_fx fx[] = {
		{"c", print_c}, {"s", print_s}, {"i", print_i},
		{"d", print_i}, {NULL, NULL}
	};
	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			format++;
			i = 0;
			if (*format == '%')
			{
				_putchar(*format);
				contador++;
			}
			else
			{
				while (fx[i].s)
				{
					if (*format == *fx[i].s)
					{
						contador += fx[i].f(args);
					}
					i++;
				}
			}
			format++;
		}
		else
		{
			_putchar(*format);
			contador++, format++;
		}
	}
	va_end(args);
	return (contador);
}
