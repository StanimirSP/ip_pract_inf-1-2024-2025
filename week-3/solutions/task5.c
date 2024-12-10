#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int isValidTriangle = (a > 0) && (b > 0) && (c > 0) && (a + b > c) && (a + c > b) && (b + c > a);

    float p = (a + b + c) / 2.0 * isValidTriangle ;

    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    area ?
        printf("Area of triangle with a = %d, b = %d, c = %d is %ld\n", a, b ,c ,area) : puts("-1");

    return 0;
}