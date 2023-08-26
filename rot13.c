#include "main.h"
#include <stdio.h>

/**
* _strchr - finds a char in a string
* @s: string
* @c: char
* Return: pointer to char in string
*/
char *_strchr(char *s, char c)
{
while (*s)
{
if (*s == c)
return (s);
s++;
}

return (NULL);
}

/**
* rot13 - encode string using rot13
* @args: va_list containing the string to be encoded
* Return: count of characters printed
*/
int rot13(va_list args)
{
char *str, *found;
char *input;
char *output;
int i, count;
char *rotated_str;

str = va_arg(args, char *);
input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

rotated_str = malloc(_strlen(str));
count = 0;

for (i = 0; str[i] != '\0'; i++)
{
found = _strchr(input, str[i]);
if (found)
rotated_str[i] = output[found - input];
else
{
rotated_str[i] = str[i];
}
}

while (rotated_str[count] != '\0')
{
_putchar(rotated_str[count]);
count++;
}
free(rotated_str);
return (count);
}
