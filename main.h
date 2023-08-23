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
void print_rev(char *s);

#endif
