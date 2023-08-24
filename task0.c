#include "main.h"

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
case 'b':
count += print_binary(args);
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
