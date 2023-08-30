#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	/* char *strtok(char *STRING, const char *delim); */
	/* return value: pointer to STRING or NULL */

	char str[] = "Hola soy nacho\n", *tok1 = NULL, *tok2, *tok3;
	char *dup = NULL;

	dup = strdup(str);

	tok1 = strtok(dup, " ");
	/* ANTES DEL STRTOK*/
	/* Hola soy nacho\n */
	/* DESPUES */
	/* Hola\0soy nacho\n */
	/*       ^          */
	/* Hola\0soy\0nacho\n */
	/*            ^       */

	tok2 = strtok(NULL, " ");
	tok3 = strtok(NULL, " ");

	printf("%s\n", tok1);
	printf("%s\n", tok2);
	printf("%s", tok3);

	printf("&dup: %p\n", dup);
	printf("*tok1: %p\n", tok1);
	printf("*tok2: %p\n", tok2);
	printf("*tok3: %p\n", tok3);
	printf("ultimo caracter -> %p\n", &dup[15]);

	printf("str -> %s\n", str);
	printf("dup -> %s\n", dup);

	free(dup);
	return (0);
}
