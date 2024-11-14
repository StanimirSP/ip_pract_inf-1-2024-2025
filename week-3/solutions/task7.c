#include <stdio.h>
#include <math.h>

int main() {
    long a, b, c; // long - to be sure
    scanf("%ld %ld %ld", &a, &b, &c);

    const double d = b * b - 4 * a * c;

    double sol1, sol2;
    int solCount;

    a != 0 ?
        d > 0 ?
            ( sol1 = (-b - sqrt(d)) / (2 * a) ) +
            ( sol2 = (-b + sqrt(d)) / (2 * a) ) +
            (solCount = 2) :
        d == 0 ?
            ( sol1 = (-b - sqrt(d)) / (2 * a) ) +
            ( solCount = 1 ) :
        (solCount = 0) :

    b != 0 ?
        ( sol1 = -c / (double)b ) + 
        ( solCount = 1 ) :

    c == 0 ?
        ( solCount = -1 ) : 
    ( solCount = 0 );

    solCount == 2 ?
        printf("x1 = %.3lf, x2 = %.3lf\n", sol1, sol2) :
    solCount == 1 ?
        printf("x1 = x2 = %.3lf\n", sol1) :
    solCount == 0 ?
        puts("No solutions") :
    puts("Any x is solution");
    
    return 0;
}