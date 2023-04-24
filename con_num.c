#include "main.h"

/**
 * print_hex - E
 * @para: ..
 * @a: ..
 * Return: ..
 */

int print_hex(va_list a, alx_t *para)
{
	unsigned long l;
	char *s;
	int i = 0;

	if (para->l_modifier)
		l = (unsigned long)va_arg(a, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(a, unsigned int);
	else
		l = (unsigned int)va_arg(a, unsigned int);

	s = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	if (para->hashtag_flag && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	para->unsign = 1;
	return (i += print_number(s, para));
}

/**
 * print_HEX - E
 * @a: argu
 * @para: ..
 * Return: bytes
 */

int print_HEX(va_list a, alx_t *para)
{
	char *s;
	int i = 0;
	unsigned long l;


	if (para->l_modifier)
		l = (unsigned long)va_arg(a, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(a, unsigned int);
	else
		l = (unsigned int)va_arg(a, unsigned int);

	s = convert(l, 16, CONVERT_UNSIGNED, para);
	if (para->hashtag_flag && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	para->unsign = 1;
	return (i += print_number(s, para));
}

/**
 * print_octal - E
 * @a: ..
 * @para: ..
 * Return: bytes
 */

int print_octal(va_list a, alx_t *para)
{
	int i = 0;
	char *s;
	unsigned long l;

	if (para->l_modifier)
		l = (unsigned long)va_arg(a, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(a, unsigned int);
	else
		l = (unsigned int)va_arg(a, unsigned int);

	s = convert(l, 8, CONVERT_UNSIGNED, para);
	if (para->hashtag_flag && l)
	{
		*--s = '0';
	}
	para->unsign = 1;
	return (i += print_number(s, para));
}

/**
 * print_binary - E
 * @a: ..
 * @para: ..
 * Return: int.
 */

int print_binary(va_list a, alx_t *para)
{
	unsigned int x = va_arg(a, unsigned int);
		char *s = convert(x, 2, CONVERT_UNSIGNED, para);
	int i = 0;

	if (para->hashtag_flag && x)
		*--s = '0';
	para->unsign = 1;
	return (i += print_number(s, para));
}
