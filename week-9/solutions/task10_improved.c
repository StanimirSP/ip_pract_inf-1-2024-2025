#include <stdio.h>

#define MAX_SZ 1024

void read_int_array(int* arr, unsigned sz)
{
	for(unsigned i = 0; i < sz; i++)
		scanf("%d", &arr[i]);
}

void print_int_array(const int* arr, unsigned sz)
{
	for(unsigned i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

unsigned remove_if(int* arr, unsigned sz, int condition(int))
{
	unsigned new_sz = 0;
	for(unsigned i = 0; i < sz; i++)
		if(!condition(arr[i]))
			arr[new_sz++] = arr[i];
	return new_sz;
}

int divisible_by_5(int n)
{
	return n % 5 == 0;
}

int less_than_100(int n)
{
	return n < 100;
}

int is_prime(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int main(void)
{
	unsigned size;
	scanf("%u", &size);
	if(size > MAX_SZ)
	{
		printf("the largest supported size is %d\n", MAX_SZ);
		return 1;
	}

	int arr[MAX_SZ];
	read_int_array(arr, size);

	//size = remove_if(arr, size, divisible_by_5); // note that there is no (...) after divisible_by_5
	//size = remove_if(arr, size, less_than_100); // note that there is no (...) after less_than_100
	size = remove_if(arr, size, is_prime); // note that there is no (...) after is_prime

	print_int_array(arr, size);
	return 0;
}

/*
10
150 17 -500 -17 45 -208 4 7 -12 129
*/

// notice the code repetition without using higher order functions
// and we should another for every new remove condition we want to use
/*
unsigned remove_if_divisible_by_5(int* arr, unsigned sz)
{
	unsigned new_sz = 0;
	for(unsigned i = 0; i < sz; i++)
		if(!divisible_by_5(arr[i]))
			arr[new_sz++] = arr[i];
	return new_sz;
}

unsigned remove_if_less_than_100(int* arr, unsigned sz)
{
	unsigned new_sz = 0;
	for(unsigned i = 0; i < sz; i++)
		if(!less_than_100(arr[i]))
			arr[new_sz++] = arr[i];
	return new_sz;
}

unsigned remove_if_prime(int* arr, unsigned sz)
{
	unsigned new_sz = 0;
	for(unsigned i = 0; i < sz; i++)
		if(!is_prime(arr[i]))
			arr[new_sz++] = arr[i];
	return new_sz;
}
*/
