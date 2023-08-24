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
sentence = 0;
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);
sentence = handle_format(format, args);

va_end(args);
return (sentence);
}
