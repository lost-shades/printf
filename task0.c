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
* @args: pointer to string
* Return: count if successful
*/
int print_string(va_list args)
{
char *s;
int count;

count = 0;
s = va_arg(args, char *);
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
int count;
int i;

count = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%' && format[i + 1] != '\0')
{
i++;
switch (format[i])
{
case 'c':
putka(va_arg(args, int));
count++;
break;
case 's':
count += print_string(args);
break;
case '%':
putka('%');
count++;
break;
case 'i':
case 'd':
count += print_num(args);
break;
default:
putka('%');
putka(format[i]);
count += 2;
break;
}
}
else
{
putka(format[i]);
count++;
}
}
return (count);
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

