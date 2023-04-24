#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - E
 * @unsign: flag
 * @plus_flag: ..
 * @space_flag: ..
 * @hashtag_flag: ..
 * @zero_flag: ..
 * @minus_flag: ..
 *
 * @width: ..
 * @precision: ..
 * @h_modifier: ..
 * @l_modifier: ..
 *
 */

typedef struct parameters
{
	unsigned int unsign       : 1;

	unsigned int plus_flag    : 1;
	unsigned int space_flag   : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag    : 1;
	unsigned int minus_flag   : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier   : 1;
	unsigned int l_modifier   : 1;
} alx_t;

/**
 * struct specifier - E
 * @specifier: ..
 * @f: ..
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, alx_t *);
} specifier_t;

/*print_num.c mod*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, alx_t *params);
int print_number_left_shift(char *s, alx_t *params);
int print_number_right_shift(char *s, alx_t *params);

/*params.c mod */
void init_params(alx_t *params, va_list ap);

/*string_fields.c mod */
char *get_precision(char *s, alx_t *params, va_list ap);

/** printf.c mod */
int _printf(const char *format, ...);

/*_put.c mud */
int _puts(char *str);
int _putchar(int c);

/*print_fun.c mod */

int print_char(va_list ap, alx_t *params);
int print_int(va_list ap, alx_t *params);
int print_string(va_list ap, alx_t *params);
int print_percent(va_list ap, alx_t *params);
int print_S(va_list ap, alx_t *params);

/** num.c modu */
char *convert(long int num, int base, int flag, alx_t *params);
int print_unsigned(va_list ap, alx_t *params);
int print_address(va_list ap, alx_t *params);

/**specifiers.c mod */
int (*get_specifier(char *s))(va_list ap, alx_t *params);
int get_print_func(char *s, va_list ap, alx_t *params);
int get_flag(char *s, alx_t *params);
int get_modifier(char *s, alx_t *params);
char *get_width(char *s, alx_t *params, va_list ap);

/* conv_num.c mod */
int print_octal(va_list ap, alx_t *params);
int print_binary(va_list ap, alx_t *params);
int print_hex(va_list ap, alx_t *params);
int print_HEX(va_list ap, alx_t *params);

/* simple_print.c mod */
int print_from_to(char *start, char *stop, char *except);
int print_rot13(va_list ap, alx_t *params);
int print_rev(va_list ap, alx_t *params);

#endif
