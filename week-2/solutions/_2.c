#include <stdio.h>

int main(void){
    double r;
    const double pi = 3.14;
    scanf("%lf", &r);
    int isValid = r > 0;
	const double circumference = 2 * pi * r;
    const double area = r * r * pi;
    ( isValid && printf("Circumference: %.2lf\nArea: %.2lf\n", circumference, area) ) || printf("Invalid data!\n");
    return 0;
}
