#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *const envp[])
{
	int i = 0;

	/* int execve(const char *pathname, char *const argv[],
				  char *const envp[]); */
	++argv;

	if (execve(argv[0], argv, envp) == -1)
		printf("Se cago todo otra vez\n");

	return (0);
}
