#include "main.h"

/**
* convert_to_binary - converts an unsigned int to binary representation
* @num: the unsigned int to be converted
* @binary: a char array to store the binary representation
* @length: length of the binary representation
*/

void convert_to_binary(unsigned int num, char *binary, int length)
{
int i;
  
for (i = length - 1; i >= 0; i--)
{
binary[i] = (num % 2) + '0';
num /= 2;
}
}
