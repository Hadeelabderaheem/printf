#include "main.h"

/**
 * get_flags - Calculates the active flags
 * @format: Formatted string in which to print the arguments
 * @n: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *n)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, curr_ind;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_ind = *n + 1; format[curr_ind] != '\0'; curr_ind++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[curr_ind] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*n = curr_ind - 1;

	return (flags);
}
