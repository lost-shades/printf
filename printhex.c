#include "main.h"

/**
* print_hex - function to print a number in hexadecimal format
* @num: the number to be printed
* @width: minimum width of the output (padded with zeros if necessary)
* Return: count if successful
*/
int print_hex(unsigned long num, int width)
{
char buffer[20];
int count = 0;

if (num == 0)
{
putka('0');
count++;
}
else
{
int i = sizeof(buffer) - 1;
buffer[i] = '\0';

while (num != 0)
{
int digit = num % 16;
buffer[--i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
num /= 16;
}

while (i > sizeof(buffer) - width)
{
buffer[--i] = '0';
}

count += print_string(buffer + i);
}

return count;
}
