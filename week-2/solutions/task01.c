#include <stdio.h>

/*
   The whole task comes down to finding the (doubled) sum of the distances.
   We can do so by observing that the distances form an arithmetic sequence
   with an initial term init = 2 and a difference diff = 3.
*/

int main(void)
{
	const unsigned init = 2, diff = 3;
	unsigned N;
	scanf("%u", &N);
	const unsigned long long last = init + (N - 1) * diff;
	const unsigned long long doubled_sum = N * (init + last);
	printf("%llu\n", doubled_sum);
	return 0;
}
