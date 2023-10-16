#include "main.h"

/**
 * get_width - counts the width for printing
 * @format: formatted string in which to prints the arguments.
 * @i: list of arguments to be printed.
 * @list: List of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_ind;
	int width = 0;

	for (curr_ind = *i + 1; format[curr_ind] != '\0'; curr_ind++)
	{
		if (is_digit(format[curr_ind]))
		{
			width *= 10;
			width += format[curr_ind] - '0';
		}
		else if (format[curr_ind] == '*')
		{
			curr_ind++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_ind - 1;

	return (width);
}
