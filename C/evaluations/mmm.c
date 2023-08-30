#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void bubble_sort(int *array, int size);

#define ARR_SIZE 1024

int main(int ac, char **av)
{
	size_t n = 0;
	char *buffer = NULL;
	FILE *file_p = NULL;
	int array[ARR_SIZE], size = 0, i = 0, media = 0, mediana = 0, moda = 0, *moda_arr, max = 0;

	if (ac != 2)
	{
		printf("Usage: %s <filename>\n", av[0]);
		return (EXIT_FAILURE);
	}

	// av[0] -> ./a.out
	// av[1] -> numbers

	file_p = fopen(av[1], "r");
	if (file_p == NULL)
	{
		dprintf(STDERR_FILENO, "Can't open file\n");
		perror(av[1]);
		return (EXIT_FAILURE);
	}

	i = 0;

	while (getline(&buffer, &n, file_p) != EOF)
	{
		// buffer -> 'hola 24\n'
		array[i] = atoi(buffer);
		// array[i] -> 24
		size++, i++;
	}

	for (i = 0; i < size; i++)
	{
		media += array[i];
	}
	media /= size;

	bubble_sort(array, size);

	if (size % 2 == 0)
	{
		mediana = (array[size / 2] + array[(size / 2) + 1]) / 2;
	}
	else
		mediana = array[size / 2];

	max = array[0];

	for (i = 1; i < size; i++)
		if (max < array[i])
			max = array[i];

	moda_arr = calloc(max, sizeof(int));

	for (i = 0; i < max; i++)
	{
		moda_arr[array[i]] += 1;
	}

	size = max;
	max = 0;
	for (i = 1; i < size; i++)
	{
		if (moda_arr[max] < moda_arr[i])
			max = i;
	}
	moda = max;

	if (fclose(file_p) == EOF)
	{
		dprintf(STDERR_FILENO, "Can't close file\n");
		perror(av[1]);
		return (EXIT_FAILURE);
	}

	file_p = fopen("results.txt", "w");

	fprintf(file_p, "media: %d\n", media);
	fprintf(file_p, "mediana: %d\n", mediana);
	fprintf(file_p, "moda: %d\n", moda);

	fclose(file_p);

	return (EXIT_SUCCESS);
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubble_sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
