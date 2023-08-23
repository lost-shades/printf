#include "main.h"

/**
* conversion_specifier - checks for conversion specifiers
* @specifer: the characters to check
* @args: list of argument.
* Return: void
*/

void conversion_specifier(char specifier, va_list args) 
{
switch (specifier) 
{
case 'u':
unsigned int num_u = va_arg(args, unsigned int);
_printf("%u", num_u);
break;
case 'o':
unsigned int num_o = va_arg(args, unsigned int);
_printf("%o", num_o);
break;
case 'x':
unsigned int num_x = va_arg(args, unsigned int);
_printf("%x", num_x);
break;
case 'X':
unsigned int num_X = va_arg(args, unsigned int);
_printf("%X", num_X);
break;
}
}

