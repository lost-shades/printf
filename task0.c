#include "main.h"

/**
* choose_specifier - function that chooses specifier
* @c: a char
* @args: argument list
* Return: counter to chars
*/

int choose_specifier(char c, va_list args)
{
int counter;

counter = 0;
switch (c)
{
case 'c':
putka(va_arg(args, int));
counter++;
break;
case 's':
counter += print_string(args);
break;
case '%':
putka('%');
counter++;
break;
case 'i':
case 'd':
counter += print_num(args);
break;
case 'b':
counter += print_binary(args);
break;
default:
putka('%');
putka(format[i]);
counter += 2;
break;
}
return (counter);
}

/**
* handle_format - function that handles format for _printf
* @format: pointer to the characters to be printed
* @args: variable name
* Return: sentence if successful
*/

int handle_format(const char *format, va_list args)
{
int count = 0, i;

for (i = 0; format[i] && format[i] != '\0'; i++)
{
if (format[i] == '%' && format[i + 1] != '\0')
{
i++;
count += choose_specifier(format[i], args);
}
else
{
putka(format[i]);
count++;
}
}
return (count);
}
