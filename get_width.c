#include "main.h"
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @x: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *x, va_list list)
{
	int curr_y;
	int width = 0;

	for (curr_y = *x + 1; format[curr_y] != '\0'; curr_y++)
	{
		if (is_digit(format[curr_y]))
		{
			width *= 10;
			width += format[curr_y] - '0';
		}
		else if (format[curr_y] == '*')
		{
			curr_y++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*x = curr_y - 1;
	return (width);
}

