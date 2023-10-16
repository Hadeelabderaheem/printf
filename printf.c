#include "main.h"

void print_buffer(char buffer[], int *buffInd);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed charctores.
 */
int _printf(const char *format, ...)
{
	int   buffInd = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (int i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffInd++] = format[i];
			if (buffInd == BUFF_SIZE)
				print_buffer(buffer, &buffInd);
		}
	print_buffer(buffer, &buffInd);
	va_end(list);
}
/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of charctores
 * @buffInd: Index at which to add next charctor
 */
void print_buffer(char buffer[], int *buffInd)
{
	if (*buffInd > 0)
		write(1, &buffer[0], *buffInd);
	*buffInd = 0;
}
