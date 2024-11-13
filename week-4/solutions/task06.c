#include <stdio.h>

int main(void)
{
	int x, y;
	if(scanf("%d%d", &x, &y) != 2)
	{
		puts("bad input");
		return 1;
	}

	printf("x = %d, y = %d\n", x, y);

	x ^= y;
	y ^= x;
	x ^= y;

	printf("x = %d, y = %d\n", x, y);

	return 0;
}