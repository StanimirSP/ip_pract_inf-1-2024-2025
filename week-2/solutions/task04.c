#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    const int discriminant = b*b - 4*a*c;
	const unsigned solutionsCnt = (discriminant == 0) + 2*(discriminant > 0);

	a ? printf("Solutions count: %u\n", solutionsCnt) : printf("a != 0 expected\n");
    
    return 0;
}
