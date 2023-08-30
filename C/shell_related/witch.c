#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *_getenv(const char *var);
char *_witch(const char *name);
extern char **environ;

int main(int ac, char **av)
{
	char *value = NULL;

	value = _witch(av[1]);

	if (value)
	{
		printf("value -> %s\n", value);
		free(value);
		return (0);
	}

	return (1);
}

char *_witch(const char *name)
{
	/* name -> ls */
	/* directory -> /usr/bin */
	/* fullpath -> /usr/bin/ls */
	/*                     ^^^ */
	char *path = _getenv("PATH"), *directory = NULL, *fullpath = NULL;
	struct stat st = {0};

	directory = strtok(path, ":");

	while (directory)
	{
		fullpath = malloc(sizeof(char) * (strlen(directory) + strlen(name) + 2));
		
		strcpy(fullpath, directory);
		strcat(fullpath, "/");
		strcat(fullpath, name);

		

		if (stat(fullpath, &st) == 0)
		{
			free(path);
			return (fullpath);
		}
		free(fullpath);
		directory = strtok(NULL, ":");
	}


	free(path);
	return (NULL);
}

char *_getenv(const char *var)
{
	int i = 0;
	char *dup = NULL, *name = NULL, *value = NULL;

	for (; environ[i]; i++)
	{
		dup = strdup(environ[i]);

		name = strtok(dup, "=");

		if (strcmp(name, var) == 0)	
		{
			value = strdup(strtok(NULL, "="));
			free(dup);
			break;
		}

		free(dup);
	}
	return (value);
}

/*

	["A=12", "B=123", "C=42"]

LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=nacho
DISPLAY=:0
SHLVL=2
XDG_RUNTIME_DIR=/mnt/wslg/runtime-dir
*/
