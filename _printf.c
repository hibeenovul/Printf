#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - printf function
 * @format: format function
 * char - character function
 * Return: 0
 */
int _printf(const char *format, ...):
{
	va_list args;
	va_start(args, format);
	count;

	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
			format++;
	}
	va_end(args);
		return (count);
}
