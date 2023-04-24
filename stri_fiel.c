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
		x = va_arg(ap, int);
		q++;
	}
	else
	{
		while (_isdigit(*q))
			x = x * 10 + (*q++ - '0');
	}
	params->precision = x;
	return (q);
}
