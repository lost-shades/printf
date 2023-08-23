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
if (s == NULL)
s = "(null)";
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
int count, i;

count = 0;
for (i = 0; format[i] && format[i] != '\0'; i++)
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
case 'u':
unsigned int num_u = va_arg(args, unsigned int);
count += putka(args);
break;
case 'o':
unsigned int num_o = va_arg(args, unsigned int);
count += putka(args);
break;
case 'x':
unsigned int num_x = va_arg(args, unsigned int);
count += putka(args);
break;
case 'X':
unsigned int num_X = va_arg(args, unsigned int);
count += putka(args);
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
sentence = 0;
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);
sentence = handle_format(format, args);

va_end(args);
return (sentence);
}

