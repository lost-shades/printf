#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* print_num - prints an integer
* @args: argument holder
* Return: characters printed
*/
int print_num(va_list args)
{
int chars_printed;
unsigned int n;
unsigned int m, d, count;

n = va_arg(args, unsigned int);
chars_printed = 0;

if ((signed int) n < 0)
{
putka('-');
m = -n;
}
else
{
m = n;
}

d = m;
count = 1;

while (d > 9)
{
d /= 10;
count *= 10;
}


for (; (signed int) count >= 1; count /= 10)
{
putka((m / count) % 10 + '0');
chars_printed++;
}

return (chars_printed);
}

int v(char, n);

/**
 *unit - prints integers
 *bin _ 
