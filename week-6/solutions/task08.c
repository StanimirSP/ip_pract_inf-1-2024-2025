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

	double N;
	if(scanf("%lf", &N) != 1 || N <= 0)
	{
		puts("bad input");
		return 1;
	}

	printf("Generating a random floating-point number in [0, %lf):\n", N);
	double random_variable = (double)(rand()) / (RAND_MAX + 1.0); // `random_variable` is in [0, 1)
	random_variable *= N; // multiplying by `N` sends it in [0, N)
	printf("%lf\n", random_variable);

	return 0;
}