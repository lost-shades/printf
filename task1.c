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
if (n == 0)
{
putka('0');
return 0;
}

int binary[32];  /* Assuming 32-bit integers */
int i = 0;

while (n > 0)
{
binary[i] = n % 2;
n /= 2;
i++;
}
for (int j = i - 1; j >= 0; j--) {
_putchar(binary[j] + '0');
}
return 0;
}
