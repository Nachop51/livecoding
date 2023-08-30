#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int random = 0, counter = 0;
	char *arr[] = {
		"Gonza Cabaleiro",
		"Ignacio Gomez",
		"Joaquin Jones",
		"Gaston Larroque",
		"Micaela Percovich",
		"Rodrigo Mato"
	};

	srand(time(0));

	for (int i = 0; counter < 6; i++)
	{
		random = rand() % 6;
		if (arr[random][0] != '\0')
		{
			printf("%s\t", arr[random]);
			arr[random] = "";
			++counter;
		}
	}
	printf("\n");
	return (0);
}
