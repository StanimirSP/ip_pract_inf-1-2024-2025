#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    double answer = (a+b+c) / 3.0; // note that (a+b+c) / 3 will give an integer result
   								   // despite storing the result in a variable of type double

    printf("%.2lf\n", answer);
    
    return 0;
}
