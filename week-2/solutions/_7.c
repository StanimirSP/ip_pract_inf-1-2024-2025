#include <stdio.h>

int main(void) {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    
    double answer = (a+b+c) / 3;

    printf("%.2lf\n", answer);
    
    return 0;
}