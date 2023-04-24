#include "main.h"

/**
 * get_precision - E
 * @q: f s
 * @params: parameters
 * @ap: argument poin
 * Return: ..
 */

char *get_precision(char *q, alx_t *params, va_list ap)
{
	int a = 0;

	if (*q != '.')
		return (q);
	q++;
	if (*q == '.')
	{
		a = va_arg(ap, int);
		q++;
	}
	else
	{
		while (_isdigit(*q))
			a = a * 10 + (*q++ - '0');
	}
	params->precision = a;
	return (q);
}
