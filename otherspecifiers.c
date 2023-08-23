#include "main.h"

/**
* _strlen - returns length of a string
* @s: string pointer
* Return: returns the length of string
*/
int _strlen(char *s)
{
int length = 0;

while (s[length] != '\0')
{
++length;
}

return (length);
}
/**
* rot13 - encodes a string using rot13
* @s: input string.
* Return: the pointer to dest.
*/

char *rot13(char *s)
{
int count = 0, i;

char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

while (*(s + count) != '\0')
{
for (i = 0; i < 52; i++)
{
if (*(s + count) == alphabet[i])
{
	*(s + count) = rot13[i];
	break;
}
}
count++;
}
return (s);
}

/**
* print_rev - prints in reverse order
* @s: the string to be printed in reverse
*/

void print_rev(char *s)
{
int length = _strlen(s) - 1;

while (length >= 0)
{
putka(s[length]);
length--;
}
putka('\n');
}
