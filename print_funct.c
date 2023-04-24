#include "main.h"

/**
 * print_char - function that prints character
 * @list: arguments list pointer
 * @params: params for the structure
 *
 * Return: number of characters there
*/
int print_char(va_list list, alx_t *params)
{
	char pd_ch = ' ';
	unsigned int pd = 1, add = 0, sh = va_arg(list, int);

	if (params->minus_flag)
		add += _putchar(sh);
	while (pd++ < params->width)
		add += _putchar(pd_ch);
	if (!params->minus_flag)
		add += _putchar(sh);
	return (add);
}

/**
 * print_int - function that prints integer
 * @list: arguments list pointer
 * @params: params for the structure
 *
 * Return: number of characters there
*/

int print_int(va_list list, alx_t *params)
{
	long T;

	if (params->l_modifier)
		T = va_arg(list, long);
	else if (params->h_modifier)
		T = (short int)va_arg(list, int);
	else
		T = (int)va_arg(list, int);
	return (print_number(convert(T, 10, 0, params), params));
}

/**
 * print_string - function that prints string
 * @list: arguments list pointer
 * @params: params for the structure
 *
 * Return: number of characters there
*/

int print_string(va_list list, alx_t *params)
{
	char *st = va_arg(list, char *), pd_ch = ' ';
	unsigned int pd = 0, add = 0, i = 0, j;

	(void)params;
	switch ((int)(!st))
	case 1:
		st = NULL_STRING;

	j = pd = _strlen(st);
	if (params->precision < pd)
		j = pd = params->precision;
	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				add += _putchar(*st++);
		else
			add += _puts(st);
	}
	while (j++ < params->width)
		add += _putchar(pd_ch);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				add += _putchar(*st++);
		else
			add += _puts(st);
	}
	return (add);
}

/**
 * print_percent - E
 * @a: ..
 * @para:..
 * Return: int.
 */

int print_percent(va_list a, alx_t *para)
{
	(void)a;
	(void)para;
	return (_putchar('%'));
}

/**
 * print_S - E
 * @a: ..
 * @para: ..
 * Return: int.
 */

int print_S(va_list a, alx_t *para)
{
	char *x = va_arg(a, char *);
	char *h;
	int s = 0;

	if ((int)(!x))
		return (_puts(NULL_STRING));
	for (; *x; x++)
	{
		if ((*x > 0 && *x < 32) || *x >= 127)
		{
			s += _putchar('\\');
			s += _putchar('x');
			h = convert(*x, 16, 0, para);
			if (!h[1])
				s += _putchar('0');
			s += _puts(h);
		}
		else
		{
			s += _putchar(*x);
		}
	}
	return (s);
}
