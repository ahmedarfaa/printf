#include "main.h"

/**
 * print_from_to - E
 * @s: start
 * @st: stop
 *
 * @ex: exept
 * Return: number of bytes
 */

int print_from_to(char *s, char *st, char *ex)
{
	int m = 0;

	while (s <= st)
	{
		if (s != ex)
			m += _putchar(*s);
		s++;
	}
	return (m);
}

/**
 * print_rev - E
 * @a: string
 * @para: the parameters
 * Return: num of bytes printed
 */

int print_rev(va_list a, alx_t *para)
{
	int l, sum = 0;
	char *s = va_arg(a, char *);
	(void)para;

	if (s)
	{
		for (l = 0; *s; s++)
			l++;
		s--;
		for (; l > 0; l--, s++)
			sum += _putchar(*s);
	}
	return (sum);
}

/**
 * print_rot13 - E
 * @a: string
 * @para: the parameters
 * Return: num of bytes
 */

int print_rot13(va_list a, alx_t *para)
{
	int x, ind;
	int c = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(a, char *);
	(void)para;

	x = 0;
	ind = 0;

	while (s[x])
	{
		if ((s[x] >= 'A' && s[x] <= 'Z') ||
			(s[x] >= 'a' && s[x] <= 'z'))
		{
			ind = s[x] - 65;
			c += _putchar(arr[ind]);
		}
		else
			c += _putchar(s[x]);
		x++;
	}
	return (c);
}
