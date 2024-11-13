#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <stddef.h> // NULL

int main(void)
{
	srand(time(NULL)); // seed the pseudo-random number generator from the system clock
					   // unless you have a specific reason not to do so,
					   // the pseudo-random number generator should only be seeded once, 
					   // before any calls to rand(), at the start of the program

	printf("Generating a random integer in [0, %d]:\n", RAND_MAX);
	int random_variable = rand();
	printf("%d\n", random_variable);

	return 0;
}