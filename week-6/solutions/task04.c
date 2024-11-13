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

	int A, B;
	if(scanf("%d%d", &A, &B) != 2 || B < A)
	{
		puts("bad input");
		return 1;
	}

	printf("Generating a random integer in [%d, %d]:\n", A, B);
	int random_variable = rand() % (B - A + 1); // `random_variable` is in [0, B-A]
	random_variable += A; // adding `A` sends it in [A, B-A+A] = [A, B]
	printf("%d\n", random_variable);

	return 0;
}