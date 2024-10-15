#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    
    
    int d1 = a % 10;
    a /= 10;
    int d2 = a % 10;
    a /= 10;
    int d3 = a % 10;
    a /= 10;
    int d4 = a % 10;
    a /= 10;

    const int answer = d1*1000 + d2*100 + d3*10 + d4;

    printf("reverse: %d\n",answer);

    return 0;
}