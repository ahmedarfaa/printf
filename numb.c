#include "main.h"

/**
 * convert - a function that converst like itoa
 * @numb: numbers input
 * @bac: input int
 * @flg: input int for flags
 * @params: parameter for the structure
 *
 * Return: it returns the strings
*/
char *convert(long int numb, int bac, int flg, alx_t *params)
{
	static char *arr;
	static char buff[50];
	char sg = 0;
	char *p;
	unsigned long n = numb;
	(void)params;

	if (!(flg & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sg = '-';
	}
	arr = flg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABDCDEF";
	p = &buff[49];
	*p = '\0';

	do {
		*--p = arr[n % bac];
		n /= bac;
	} while (n != 0);

	if (sg)
		*--p = sg;
	return (p);
}

/**
 * print_unsigned - a function that prints unsigned
 * @list: arguement list for the pointer
 * @params: parameter for the structure
 *
 * Return: it returns the printed int
*/
int print_unsigned(va_list list, alx_t *params)
{
	unsigned long t;

	if (params->l_modifier)
		t = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		t = (unsigned short int)va_arg(list, unsigned int);
	else
		t = (unsigned int)va_arg(list, unsigned int);
	params->unsign = 1;
	return (print_number(convert(t, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * print_address - a function that prints address
 * @list: arguement list for the pointer
 * @params: parameter for the structure
 *
 * Return: it returns the printed address
*/
int print_address(va_list list, alx_t *params)
{
	unsigned long int u = va_arg(list, unsigned long int);
	char *st;

	if (!u)
		return (_puts("(nil)"));
	st = convert(u, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--st = 'x';
	*--st = '0';
	return (print_number(st, params));
}
