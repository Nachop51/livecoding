#include <stdio.h>
#include <string.h>

char triangle(const char *row);

int main(void)
{
	char *str = "codewars";
	char *str2 = "circlecipher";
	char r;
	char r2;
	char r3;

	r = triangle(str);
	r2 = triangle(str2);
	r3 = triangle("");

	printf("%c = l\n", r);
	printf("%c = z\n", r2);

	return (0);
}



char triangle(const char *row)
{
	int i = 0, j = 0;
	char buf[30];

	for (i = 0; i < 30; i++)
		buf[i] = '\0';

	strcpy(buf, row);

	for (i = 0; buf[1] != '\0'; i++)
	{
		for (j = 1; buf[j] != '\0'; j++)
		{

			/*99 + 111 = 210 <--> 'c' + 'o'

			210 - 192 <-> (96 * 2) = 18

			18 + 96 = 114;

			99 + 111 - 96*/

			/* j - 1 = 0, j = 1 */

			/*printf("buf[j - 1] = %d, buf[j] = %d", buf[j - 1], buf[j]);
			printf(" = %d\n",  buf[j - 1] + buf[j] - 96);*/

			/*printf("buf[%d] + buf[%d] - 96 = %d\n", j - 1, j, buf[j - 1] + buf[j] - 96);
			printf("%d + %d - 96 = %d\n", buf[j - 1], buf[j], buf[j - 1] + buf[j] - 96);*/

			buf[j - 1] = (buf[j - 1] + buf[j]) - 192; /* 96 * 2 = 192 */


			/*printf(" BEFORE IF %d\n", buf[j - 1]);*/

			buf[j - 1] = buf[j - 1] % 26;

			if (buf[j - 1] == 0)
				buf[j - 1] = 26;

			buf[j - 1] += 96;
			/*if (buf[j - 1] > 25)
			{
				buf[j - 1] -= 26; buf[j - 1] = buf[j - 1] - 26
				printf(" INSIDE IF %d\n", buf[j - 1]);
			}*/

		}
		buf[j - 1] = '\0';
		printf("%s\n", buf);
	}
	return (buf[0]);
}
