#include "holberton.h"
/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int  i, flag;
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
		if (*format == '%')
		{
			i = 0;
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
		contador++;
		format++;
		}
	}
	va_end(args);
	return (contador);
}
