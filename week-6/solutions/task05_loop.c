#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <stddef.h> // NULL
#include <limits.h> // ULLONG_MAX

int main(void)
{
	srand(time(NULL)); // seed the pseudo-random number generator from the system clock
					   // unless you have a specific reason not to do so,
					   // the pseudo - random number generator should only be seeded once, 
					   // before any calls to rand(), at the start of the program

	// rand() returns a pseudo-random number in [0, RAND_MAX]
	// all we know is that RAND_MAX >= 32767, i.e. we get at least 15 random bits per call of `rand()`
	// but in most systems this number is larger
	// we can find exactly how many random_bits we get per call to `rand()`
	unsigned random_bits_per_step = 0;
	for(unsigned long long rnd_max = RAND_MAX; rnd_max; rnd_max >>= 1)
		random_bits_per_step++;

	// printf("Random bits per call to rand(): %u\n", random_bits_per_step);

	// we want to generate a 64-bit random number, so we can use multiple calls to `rand()`
	// and "build" the number using bitwise operations

	const unsigned random_bit_wanted = 64;
	unsigned long long big_random_variable = 0;

	for(unsigned random_bits = 0; random_bits < random_bit_wanted; random_bits += random_bits_per_step)
	{
		big_random_variable <<= random_bits_per_step;
		big_random_variable |= rand();
	}

	printf("A random integer in [0, %llu]:\n", ULLONG_MAX);
	printf("%llu\n", big_random_variable);

	return 0;
}