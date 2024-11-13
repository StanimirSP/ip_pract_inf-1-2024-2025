#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned N, k;
	if(scanf("%u%u", &N, &k) != 2 || k >= CHAR_BIT * sizeof(k)) // CHAR_BIT is the number of bits in a byte, i.e. 8 on most systems
	{
		puts("bad input");
		return 1;
	}

	const unsigned mask_bit_k = 1u << k;
	N |= mask_bit_k; // set bit k
	printf("%u\n", N);

	return 0;
}