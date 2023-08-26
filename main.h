#ifndef PUTKA_H
#define PUTKA_H

#include <stdarg.h>
#include <unistd.h>

int putka(char c);
int _printf(const char *format, ...);
int print_num(va_list args);
int print_string(va_list args);
int handle_format(const char *format, va_list args);
int print_binary(va_list args);
int choose_specifier(char c, va_list args);
int print_reverse(va_list args);
int _strlen(char *s);
char *_strchr(char *s, char c);
int rot13(va_list args);
int print_address(va_list args);

#endif
