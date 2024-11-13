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

	double A, B;
	if(scanf("%lf%lf", &A, &B) != 2 || B < A)
	{
		puts("bad input");
		return 1;
	}

	printf("Generating a random floating-point number in [%lf, %lf):\n", A, B);
	const double interval_len = B - A;
	double random_variable = (double)(rand()) / (RAND_MAX + 1.0); // `random_variable` is in [0, 1)
	random_variable *= interval_len; // multiplying by `interval_len` sends it in [0, B-A)
	random_variable += A; // adding `A` sends it in [A, B-A+A) = [A, B)
	printf("%lf\n", random_variable);

	return 0;
}