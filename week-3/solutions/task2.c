#include <stdio.h>

int main(void) {
    char ch;
    scanf("%c", &ch);
    
    (ch >= 'a' && ch <= 'z') ?                        // if
        printf("'%c' is lower case letter.\n",ch) :   // -> true
    (ch >= 'A' && ch <= 'Z') ?                        // else if
        printf("'%c' is upper case letter.\n",ch) :   // -> true
    printf("'%c' is not a lettr.\n",ch);              // else

    return 0;
}