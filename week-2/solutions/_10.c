#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned n;
    float a1, quot;
    scanf("%f %f %u", &a1, &quot, &n);
	n > 0 || printf("invalid element index\n");
    n > 0 && printf("%lf\n", a1 * pow(quot,n-1));

    return 0;
}
