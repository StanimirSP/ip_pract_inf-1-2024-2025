#include <stdio.h>

int main(void){
    double r;
    const double pi = 3.14;
    scanf("%lf", &r);
    int isValid = r > 0;
    const double area = r * r * pi;
    ( isValid && printf("Area: %.2lf\n", area) ) || printf("Invalid data!\n");
    return 0;
}