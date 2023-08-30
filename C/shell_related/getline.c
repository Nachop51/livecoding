#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - xd
 * @argc: arg counter
 * @argv: arg vector
 *
 * Return: Ni idea
 */
int main(int argc, char const *argv[])
{

	char *buffer = NULL;	/* buffer == NULL ? dynamic : malloc, s[10] ->  */
	size_t n = 0;		/* n == 0 ? dynamic n : n fixed */
				/* FILE *stdin -> file descriptor of STANDARD INPUT */

	/* ssize_t getline(char **lineptr, size_t *n, FILE *stream); */

	while (printf("$ ") && getline(&buffer, &n, stdin) != -1)
		printf("buffer -> %s", buffer);

	free(buffer);
	return (0);
}
