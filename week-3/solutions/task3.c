#include <stdio.h>

int main(void) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int start, end;
    
    (c > b || a > d) ?                  //  ~ if (c > b || a > b)
        puts("{}") :                    //      -> true
    (                                   //  else {
        (start = a < c ? c : a) &       //     start = max(a,c); -> max gives you the bigger number
        (end = b < d ? b : d)) &        //      end = min(b,d); -> min gives you the smaller number
        printf("[%d, %d]", start, end   //      printf("[&d, %d]", start, end);    
    );                                  //  }

    return 0;
}