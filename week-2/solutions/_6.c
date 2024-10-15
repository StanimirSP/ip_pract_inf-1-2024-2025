#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    (b < a) && (a = b);
	(c < a) && (a = c);

    printf("%d\n", a);

    return 0;
}
