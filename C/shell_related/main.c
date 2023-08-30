#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i = 0;
	size_t n = 0;
	char *buffer = NULL, *arr[5], *tok;

	arr[4] = NULL;
	while (printf("$ ") && getline(&buffer, &n, stdin) != -1)
	{
		tok = strtok(buffer, "\n"), tok = strtok(buffer, " ");
		for (i = 0; tok != NULL; i++)
		{
			arr[i] = tok;
			tok = strtok(NULL, " ");
		}
		for (i = 0; arr[i]; i++)
		{
			printf("[%d] -> %s\n", i, arr[i]);
		}
	}

	free(buffer);
	return (0);
}
