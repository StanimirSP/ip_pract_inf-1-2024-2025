#include <stdio.h>

int main(void) {
    int a = '0',
        b = '1',
        c = '9',
        d = 'B',
        e = 'F';

    printf("'%c' = %d, '%c' = %d, '%c' = %d, '%c' = %d, '%c' = %d\n",
		(char)a, a, (char)b, b, (char)c, c, (char)d, d, (char)e, e);
    // printf("'0' = %d, '1' = %d, '9' = %d, 'B' = %d, 'F' = %d\n", '0', '1', '9', 'B', 'F');
    return 0;
}
