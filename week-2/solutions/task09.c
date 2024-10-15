#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

	int division_by_zero = b == 0;
	division_by_zero && printf("division by zero\n"); // OK, `printf` returns int
    division_by_zero || printf("quotient: %d\nremainder: %d\n", a / b, a % b);
    return 0;
}
// bonus question: apart from division by zero, what other (valid) values of `a` and `b` will cause undefined behavior?
