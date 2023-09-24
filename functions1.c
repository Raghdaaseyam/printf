#include "main.h"

/************************* DISPLAY UNSIGNED NUMBER *************************/
/**
 * display_unsigned - Displays an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array for handling display
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters displayed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/************* DISPLAY UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * display_octal - Displays an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array for handling display
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters displayed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[k--] = '0';

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
/************** DISPLAY UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * display_hexadecimal - Displays an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array for handling display
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters displayed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/************* DISPLAY UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * display_hexa_upper - Displays an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array for handling display
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters displayed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** DISPLAY HEXADECIMAL NUMBER IN LOWER OR UPPER **************/
/**
 * display_hexa - Displays a hexadecimal number in lower or upper case
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array for handling display
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of characters displayed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[k--] = flag_ch;
		buffer[k--] = '0';
	}

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
