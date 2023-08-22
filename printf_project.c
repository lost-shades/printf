#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * putka - function to output a char
 * @c: character to be printed
 * Return: always 0
 */
int putka(char c)
{
	write(1, &c, 1);
	return (0);
}

/**
 * print_string - function to print string
 * @s: pointer to string
 * Return: count if successful
 */

int print_string(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		putka(*s++);
		count++;
	}
	return (count);
}

/**
 * handle_format - function that handles format for _printf
 * @format: pointer to the characters to be printed
 * @args: variable name
 * Return: sentence if successful
 */

int handle_format(const char *format, va_list args)
{
	int sentence = 0;
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				putka(c);
				sentence++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				sentence += print_string(s);
			}
			else if (format[i] == '%')
			{
				putka('%');
				sentence++;
			}
			else
			{
				putka('%');
				putka(format[i]);
				sentence += 2;
			}
		}
		else
		{
			putka(format[i]);
			sentence++;
		}
	}
	return (sentence);
}

/**
 * _printf - printf string according to format specified
 * @format: The format string specifying the
 * types of arguments to be printed.
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int sentence;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	sentence = handle_format(format, args);

	va_end(args);
	return (sentence);
}

