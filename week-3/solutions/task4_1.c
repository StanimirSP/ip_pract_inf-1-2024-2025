#include <stdio.h>

int main() {
    int xCircle, yCircle, radius, x, y;

    scanf("%d %d %d", &xCircle, &yCircle, &radius);
    
    scanf("%d %d", &x, &y);
    
    const unsigned distanceSquare = (x - xCircle) * (x - xCircle) + (y - yCircle) * (y - yCircle);
    
    radius <= 0 ?
        puts("Invalid data") :
       
    (distanceSquare < radius * radius) ?
        printf("(%d, %d) is inside the circle\n", x, y) :

    (distanceSquare > radius * radius) ?
        printf("(%d, %d) is outside the circle\n", x, y) :

    printf("(%d, %d) is on the circle\n", x, y);

    return 0;
}