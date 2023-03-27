#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
void _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
				{
					char val = va_arg(args, int);

					printf("%c", val);
					break;
				}
				case 's':
				{
					char *val = va_arg(args, char*);

					printf("%s", val);
					break;
				}
				default:
				{
					putchar(*format);
					break;
				}
			}	
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}
