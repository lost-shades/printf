#ifndef PUTKA_H
#define PUTKA_H
#include <stdarg.h>
#include <unistd.h>

int putka(char c);
int _printf(const char *format, ...);
int print_num(va_list args);
int print_string(va_list args);
int handle_format(const char *format, va_list args);
int _strlen(char *s);
char *rot13(char *s);
void rev_string(char *s);
void print_rev(char *s);
void convert_to_binary(unsigned int num, char *binary, int length);
void conversion_specifier(char specifier, va_list args);
int print_hex(unsigned long num, int width);

#endif
