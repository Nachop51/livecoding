#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list_s {
	int n;
	struct list_s *next;
} list_t;

#endif
