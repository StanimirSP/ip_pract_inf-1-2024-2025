#include <stdio.h>

int main(void) {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    int aZero = a == 0;
    
    const double discriminant  = aZero * (b*b - 4*a*c);
    
    
    int noSolution = discriminant < 0;
    int twoSolutions = discriminant > 0;
    int oneSolution = (!noSolution && !twoSolutions) || aZero;
    
    (oneSolution && printf("1 real solution\n")) ||
    (twoSolutions && printf("2 real solutions\n")) ||
    printf("No real solutions\n");

    return 0;
}