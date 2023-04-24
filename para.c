#include "main.h"

/**
 * init_params - function that reset buffs
 * clear the structure vals
 * @list : argument pointer for va_list
 * @params: struct for the params
*/
void init_params(alx_t *params, va_list list)
{
	params->unsign = 0;
	params->precision = UINT_MAX;
	params->width = 0;
	params->h_modifier = 0;
	params->l_modifier = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	(void)list;
}
