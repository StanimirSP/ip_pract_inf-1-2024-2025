#include <stdio.h>

int main(void){
    double r;
    const double pi = 3.1415926536; // one may also decide to use e.g. acos(-1)
    scanf("%lf", &r);
    int isValid = r > 0;
	isValid || printf("Invalid input\n");
	const double circumference = 2 * pi * r;
    const double area = r * r * pi;
    isValid && printf("Circumference: %.2lf\nArea: %.2lf\n", circumference, area);
    return 0;
}
