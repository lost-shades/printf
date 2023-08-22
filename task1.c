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



#include <stdarg.h>
#include <unistd.h>
/**
 * printer - inputs a character into a variable address
 * @c: character to input
 * Return: always 0
 */
int printer(char c)
{
	write(1, &c, 1);
	return (0);
}
/**
 * print_num - prints an integer
 * @format: number of variable arguments
 * @args: argument holder
 * Return: characters printed
 */
int print_num(const char *format, va_list args)
{
	int chars_printed = 0;
	const char *c;
	for (c = format; *c != '\0'; ++c)
	{
		if (*c == '%')
		{
			c++;
			if (*c == 'd' || *c == 'i')
			{
				int n = va_arg(args, int);
				unsigned int m, d, count;
				if (n < 0)
				{
					printer(45);
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
					printer(((m / count) % 10) + 48);
					chars_printed++;
				}
			}
