#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"


void (*get_func(char identifier, struct format_struct *fmt_arr))(va_list *);
void print_char(va_list *arg);
void print_int(va_list *arg);
void print_float(va_list *arg);
void print_string(va_list *arg);

/**
 * print_all - prints anything(any data type)
 * @format: pointer to string of data format types
 */
void print_all(const char * const format, ...)
{
	unsigned int j = 0;
	char *separator = "";

	format_struct_ptr fmt_arr[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};
	void (*get_func_ptr)(va_list *);
	va_list args;

	va_start(args, format);

	while (format && format[j] != '\0')
	{
		get_func_ptr = get_func(format[j], fmt_arr);

		if (get_func_ptr)
		{
			printf("%s", separator);
			get_func_ptr(&args);
			separator = ", ";
		}

		j++;
	}

	va_end(args);
	printf("\n");
}
