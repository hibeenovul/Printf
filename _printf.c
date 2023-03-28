#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
/**
 * get_gunc - it is uded to get funcions
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */

int (*get_func(char x))( va_list args)
{
	int i;

	def_t func[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'d', print_d},
	{'i', print_i},
	{'b', print_binary},
	{'u', print_unsigned},
	{'o', print_octal},
	{'x', print_hexadecimal},
	{'X', print_hexa_upper}
	};

	while (func[i].def)
	{
		if (x == func[i].def)
			return (func[i].f);
		i++;
	}
	return (NULL);
}
int _printf(const char *format, ...)
{
	va_list a;
	int (*m)(va_list);
	int i, count;

	if (format == NULL)
		return (0);

	count = 0;
	va_start(a, format);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i] == '%')
			{
				count += _putchar(format[i]);
			}
			else
			{
				m = get_func(format[i + 1]);
				if (m)
				{
					count += m(a);
				}
				else
				{
					count = _putchar(format[i]) + _putchar(format[i + 1]);
				}
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		va_end(a);
		return (count);
	}
}
