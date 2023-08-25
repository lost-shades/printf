#include "main.h"

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
* print_reverse - Prints a string in reverse order using putchar
* @args: Variable argument list containing additional arguments
* Return: Updated count of characters printed.
*/
int print_reverse(va_list args)
{
char *enter = va_arg(args, char *);
int i, length, count;

length = _strlen(enter);
count = 0;

for (i = length - 1; i >= 0; i--)
{
_putchar(enter[i]);
count++;
}
return (count);
}

/**
* _strlen - calculates length of a string
* @s: pointer to string
*
* Return: int length
*/
int _strlen(char *s)
{
int length;

length = 0;
while (s[length] != '\0')
length++;
return (length);
}

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

/**
* print_binary - prints a digit in binary
* @args: va list
* Return: 0 at success
*/

int print_binary(va_list args)
{
unsigned int n = va_arg(args, unsigned int);
unsigned int cover;
int plus_zeros, count;

cover = 1 << (sizeof(unsigned int) * 8 - 1);
plus_zeros = 1;
count = 0;

if (n == 0)
{
putka('0');
count++;
return (count);
}

while (cover > 0)
{
if (n & cover)
{
plus_zeros = 0;
putka('1');
count++;
}
else if (plus_zeros)
{
putka('0');
count++;
}
cover >>= 1;
}

return (count);
}
