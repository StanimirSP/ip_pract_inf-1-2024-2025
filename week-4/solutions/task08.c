#include <stdio.h>

int main(void)
{
	unsigned k;
	if(scanf("%u", &k) != 1 || k >= 64)
	{
		puts("bad input");
		return 1;
	}

	printf("%llu\n", 1ULL << k);

	return 0;
}