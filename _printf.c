#include "main.h"

/**
 * _printf - a function that produces output according to a format
 *
 *@format: input character describes the string
 *@...: other inputs
 *
 *Return: printed variables , -1 if format is null
*/
int _printf(const char *format, ...)
{
	int add = 0;
	va_list list;
	char *q;
	char *fst;
	alx_t params = PARAMS_INIT;

	va_start(list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (q = (char *)format; *q; q++)
	{
		init_params(&params, list);
		if (*q != '%')
		{
		add += _putchar(*q);
		continue;
		}
		fst = q;
		q++;
		while (get_flag(q, &params))
		{
		q++;
		}
		q = get_width(q, &params, list);
		q = get_precision(q, &params, list);
		if (get_modifier(q, &params))
		q++;
		if (!get_specifier(q))
		add += print_from_to(fst, q,
				params.l_modifier || params.h_modifier ? q - 1 : 0);
		else
			add += get_print_func(q, list, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(list);
	return (add);
}

