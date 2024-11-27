#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SZ 1024

int generate_random_int_array(int arr[], unsigned sz, int min, int max)
{
	if(min > max)
		return 0;
	const int ingerval_len = max - min + 1;
	for(unsigned i = 0; i < sz; i++)
		arr[i] = min + rand() % ingerval_len;
	return 1;
}

void print_int_array(const int arr[], unsigned sz)
{
	for(unsigned i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	srand(time(NULL));

	unsigned N;
	int min, max;
	scanf("%u%d%d", &N, &min, &max);
	if(N > MAX_SZ)
	{
		puts("bad input: N too large");
		return 1;
	}

	int arr[MAX_SZ];
	if(!generate_random_int_array(arr, N, min, max))
	{
		puts("cannot choose elements from the empty set");
		return 1;
	}

	print_int_array(arr, N);
	return 0;
}
