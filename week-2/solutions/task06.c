#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

	int Max = a > b ? a : b; // Max = max(a,b)
	Max = Max > c ? Max : c; // Max = max(max(a, b), c) = max(a, b, c)

    printf("%d\n", Max);

    return 0;
}
