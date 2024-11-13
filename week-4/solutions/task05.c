#include <stdio.h>

int main(void)
{
	unsigned N;
	if(scanf("%u", &N) != 1)
	{
		puts("bad input");
		return 1;
	}

	const unsigned mask_low5_bits = (1u << 5) - 1;
	N ^= mask_low5_bits; // invert the 5 least significant bits
	printf("%u\n", N);

	return 0;
}