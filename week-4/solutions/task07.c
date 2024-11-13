#include <stdio.h>

int main(void)
{
	int N;
	if(scanf("%d", &N) != 1)
	{
		puts("bad input");
		return 1;
	}

	if(N & 1) puts("odd");
	else puts("even");

	return 0;
}