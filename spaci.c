#include "main.h"

/**
 * get_specifier - E
 * @a: format str
 * Return: num of bytes
 */

int (*get_specifier(char *a))(va_list ap, alx_t *params)
{
	specifier_t specifier[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"s", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int x = 0;

	while (specifier[x].specifier)
	{
		if (*a == specifier[x].specifier[0])
		{
			return (specifier[x].f);
		}
		x++;
	}
	return (NULL);
}

/**
 * get_print_func - E
 * @a: format str
 * @ap: argu
 * @params: the parameters
 * Return: num of bytes
 */

int get_print_func(char *a, va_list ap, alx_t *params)
{

	int (*f)(va_list, alx_t *) = get_specifier(a);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - E
 * @a: f s
 * @params: parameters
 *
 * Return: x.
 */

int get_flag(char *a, alx_t *params)
{
	int x = 0;

	switch (*a)
	{
		case '+':
			x = params->plus_flag = 1;
			break;
		case ' ':
			x = params->plus_flag = 1;
			break;
		case '#':
			x = params->plus_flag = 1;
			break;
		case '-':
			x = params->plus_flag = 1;
			break;
		case '0':
			x = params->plus_flag = 1;
			break;
	}
	return (x);
}

/**
 * get_width - E
 * @a: f s
 * @params: parameters
 * @ap: argu
 *
 * Return: n poi
 */

char *get_width(char *a, alx_t *params, va_list ap)
{
	int x = 0;

	if (*a == '*')
	{
		x = va_arg(ap, int);
		a++;
	}
	else
	{
		while (_isdigit(*a))
			x = x * 10 + (*a++ - '0');
	}
	params->width = x;
	return (a);
}

/**
 * get_modifier - E
 * @a: ..
 * @para: ..
 * Return: .
 */

int get_modifier(char *a, alx_t *para)
{
	int x = 0;

	switch (*a)
	{
		case 'h':
			x = para->h_modifier = 1;
			break;
		case 'l':
			x = para->l_modifier = 1;
			break;
	}
	return (x);
}
