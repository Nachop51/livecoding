#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

typedef struct my_struct_p {
	char CHARACTER;
	void (*FUNCTION)(va_list);
} my_struct_t;

void print_all(const char * const format, ...);

#endif
