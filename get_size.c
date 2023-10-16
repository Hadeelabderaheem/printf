#include "main.h"

/**
 * get_size - Calculates the size to get the argument
 * @format: formatted string in which to prints the arguments
 * @i: list of arguments to be printed.
 *
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int curr_ind = *i + 1;
	int SIZE = 0;

	if (format[curr_ind] == 'l')
		SIZE = S_LONG;
	else if (format[curr_ind] == 'h')
		SIZE = S_SHORT;

	if (SIZE == 0)
		*i = curr_ind - 1;
	else
		*i = curr_ind;

	return (SIZE);
}
