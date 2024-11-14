#include <stdio.h>

int main(void) {
    unsigned year;
    scanf("%u", &year);
    
    int isLeapYear = (year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0);
    
    isLeapYear ?                                                     // if()
        printf("%u is a leap year", year) :                          //     printf("%u is a leap year", year);
    printf("%u is not a leap year", year);                           // else printf("%u is not a leap year", year);

    return 0;
}