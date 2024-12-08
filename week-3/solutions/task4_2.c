#include <stdio.h>

int main() {
    
    double xCircle, yCircle, radius, x, y;
    scanf("%lf %lf %lf", &xCircle, &yCircle, &radius);
    scanf("%lf %lf", &x, &y);
    
    const double distanceSquare = (x - xCircle) * (x - xCircle) + (y - yCircle) * (y - yCircle);

    !(radius > 0) ?                                                           // if(!(radius > 0)) 
        puts("Invalid data") :                                                //      printf("Invalid data\n");
                                                                                            
    (distanceSquare < radius * radius) ?                                      // else if( distance < radius )  
        printf("(%lf, %lf) is inside the circle\n", x, y) :                   //      printf("(%lf, %lf) is inside the circle\n", x, y)

    (distanceSquare > radius * radius) ?                                      // else if( distance > radius )
        printf("(%lf, %lf) is outside the circle\n", x, y) :                  //      printf("(%lf, %lf) is otuside the circle\n", x, y)

    printf("(%lf, %lf) is on the circle\n", x, y);                            // else printf("(%lf, %lf) is on the circle\n", x, y)

    return 0;
}