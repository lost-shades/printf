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
int chars_printed = 0;
int n = va_arg(args, int);
unsigned int m, d, count;
if (n < 0)
{
putka('-');
m = n * -1;
}
else
m = n;
d = m;
count = 1;
while (d > 9)
{
d /= 10;
count *= 10;
}
for (; count >= 1; count /= 10)
{
putka(((m / count) % 10) + '0');
chars_printed++;
}
return (chars_printed);
}
