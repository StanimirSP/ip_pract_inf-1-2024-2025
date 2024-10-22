#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

	b ? printf("quotient: %d\nremainder: %d\n", a / b, a % b) : printf("division by zero\n");
    return 0;
}
// bonus question: apart from division by zero, what other (valid) values of `a` and `b` will cause undefined behavior?
