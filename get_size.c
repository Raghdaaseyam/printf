#include "main.h"

/**
 * calculate_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 *
 * Return: Size specifier
 */
int get_size(const char *format, int *c)
{
	int curr_i = *c + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*c = curr_i - 1;
	else
		*c = curr_i;

	return (size);
}
