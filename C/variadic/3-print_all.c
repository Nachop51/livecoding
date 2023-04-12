#include "variadic_functions.h"
#include <stdio.h>

void print_char(va_list args) 
{
	char c = va_arg(args, int);

	printf("%c", c);
}

void print_string(va_list args) 
{
	char *string = va_arg(args, char *);

	if (!string)
		string = "(nil)";
	printf("%s", string);
}

void print_float(va_list args) 
{
	float flotante = va_arg(args, double);

	printf("%f", flotante);
}

void print_integer(va_list args) 
{
	int num = va_arg(args, int);

	printf("%d", num);
}

void print_all(const char * const format, ...)
{
	int i = 0, j = 0;
	my_struct_t functions[] = {
		{'c', print_char},
		{'f', print_float},
		{'i', print_integer},
		{'s', print_string},
		{'\0', NULL}
	};
	va_list args;

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		j = 0;

		while (functions[j].CHARACTER != '\0')
		{
			if (functions[j].CHARACTER == format[i])
				functions[j].FUNCTION(args);
			j++;
		}
		i++;
	}
	putchar(10);
	va_end(args);
}
