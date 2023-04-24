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
	char *a;
	int i = 0;

	if (para->l_modifier)
		l = (unsigned long)va_arg(a, unsigned long);
	else if (para->h->modifier)
		l = (unsigned short int)va_arg(a, unsigned int);
	else
		l = (unsigned int)va_arg(a, unsigned int);

	a = convert(1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	if (para->hashtag_flag && l)
	{
		*--a = 'x';
		*--a = '0';
	}
	para->unsign = 1;
	return (i += print_number(a, para));
}

/**
 * print_HEX - E
 * @a: argu
 * @para: ..
 * Return: bytes
 */

int print_HEX(va_list a, alx_t *para)
{
	char *a;
	int i = 0;
	unsigned long l;


	if (para->l_modifier)
		l = (unsigned long)va_arg(a, unsigned long);
	else if (para->h->modifier)
		l = (unsigned short int)va_arg(a, unsigned int);
	else
		l = (unsigned int)va_arg(a, unsigned int);

	a = convert(1, 16, CONVERT_UNSIGNED, para);
	if (para->hashtag_flag && l)
	{
		*--a = 'X';
		*--a = '0';
	}
	para->unsign = 1;
	return (i += print_number(a, para));
}

/**
 * print_octal - E
 * @a: ..
 * @para: ..
 * Return: bytes
 */

int print_octal(va_list a, alx_t para)
{
	int i = 0;
	char *a;
	unsigned long l;

	if (para->l_modifier)
		l = (unsigned long)va_arg(a, unsigned long);
	else if (para->h->modifier)
		l = (unsigned short int)va_arg(a, unsigned int);
	else
		l = (unsigned int)va_arg(a, unsigned int);

	a = convert(1, 8, CONVERT_UNSIGNED, para);
	if (para->hashtag_flag && l)
	{
		*--a = '0';
	}
	para->unsign = 1;
	return (i += print_number(a, para));
}
