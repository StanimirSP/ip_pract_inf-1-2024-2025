#include <stdio.h>


int main(void){
    char a, b;
    scanf("%c %c", &a, &b);
    
    char temp = a;
    a = b;
    b = temp;
    printf("a = %c, b = %c\n", a, b);
    return 0;
}