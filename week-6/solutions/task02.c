#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <stddef.h> // NULL

int main(void)
{
	srand(time(NULL)); // seed the pseudo-random number generator from the system clock
					   // unless you have a specific reason not to do so,
					   // the pseudo - random number generator should only be seeded once, 
					   // before any calls to rand(), at the start of the program

	unsigned N;
	if(scanf("%u", &N) != 1 || N < 1)
	{
		puts("bad input");
		return 1;
	}

	printf("Generating a random integer in [0, %u]:\n", N - 1);
	int random_variable = rand() % N;
	printf("%d\n", random_variable);

	return 0;
}