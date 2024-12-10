#include <stdio.h>

int main(void) {
    int num = 0;
    scanf("%d", &num);
    unsigned absNum = (num < 0 ? -num : num);
    printf("Absolute value of %d is %d.\n", num, absNum);
    return 0;
}