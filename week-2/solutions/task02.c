#include <stdio.h>

int main(void){
    double r;
    const double pi = 3.1415926536; // one may also decide to use e.g. acos(-1)
    scanf("%lf", &r);
	const double circumference = 2 * pi * r;
    const double area = r * r * pi;
	r > 0 ? printf("Circumference: %.2lf\nArea: %.2lf\n", circumference, area) : printf("Invalid input\n");
    return 0;
}
