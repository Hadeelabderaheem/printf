#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - This is a printf function
 * @format: this is the formate which format the codes
 * Return: Returns a characters in the codes
 */
int _printf(const char *format, ...)
{
	int k, prted = 0, chars_printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &k);
			width = get_width(format, &k, list);
			precision = get_precision(format, &k, list);
			size = get_size(format, &k);
			++k;
			prted = handle_print(format, &k, list, buffer,
				flags, width, precision, size);
			if (prted == -1)
				return (-1);
			chars_printed += prted;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (chars_printed);
}

/**
 * print_buffer -This  prints the contents of  buffer if present.
 * @buffer: Array of chars to be returned.
 * @buff_ind: This is the index at which to add next char
 * represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
