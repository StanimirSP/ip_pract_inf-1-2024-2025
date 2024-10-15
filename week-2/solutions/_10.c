#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    float a1, d;
    scanf("%f %f %d", &a1, &d, &n);
    
    double answer = a1 * pow(d,n-1);
    
    printf("%lf\n", answer);
    return 0;
}