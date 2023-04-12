#include <stdio.h>

int sum(int a, int b)
{
    printf("sum &a = %p\n", &a);
    printf("sum &b = %p\n", &b);
	return (a + b);
}

int main(void)
{
	int a = 4;
	int b = 5;
	int resultado = sum(a, b);

    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("sum a + b = %d\n", resultado);

	return (0);
}


