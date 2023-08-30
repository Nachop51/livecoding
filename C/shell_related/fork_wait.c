#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int status;
	pid_t child_pid = -1;

	child_pid = fork();
	/* child_pid -> valor en el proceso hijo: 0 */
	/* child_pid -> valor en el proceso padre: otro */
	if (child_pid == -1)
		printf("se cago todo\n"), exit(EXIT_FAILURE);
	if (child_pid == 0)
	{
		printf("ESTOY EN EL PROCESO HIJO\n");
	}
	else
	{
		wait(&status);
		printf("SE MURIO MI HIJO\n");
	}
	return (0);
}
