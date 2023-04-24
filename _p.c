#include "main.h"

/**
 * _puts - E
 * @s: string
 * Return: void
 */

int _puts(char *s)
{
	char *x = s;

	while (*s)
		_putchar(*s++);
	return (s - x);
}

/**
 * _putchar - E
 * @a: character
 * Return: 1 on success
 */

int _putchar(int a)
{
	static int x;

	static char buf[OUTPUT_BUF_SIZE];

	if (a == BUF_FLUSH || x >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (a != BUF_FLUSH)
		buf[x++] = a;
	return (1);
}
