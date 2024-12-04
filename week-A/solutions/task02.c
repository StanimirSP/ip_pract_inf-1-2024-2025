#include <stdio.h>

#define MAX_SZ 1024

void read_int_array(int* arr, unsigned sz)
{
	for(unsigned i = 0; i < sz; i++)
		scanf("%d", &arr[i]); // same as `scanf("%d", arr + i);`
}

// prints the range [first, last) to stdout
void print_int_range(const int* first, const int* last)
{
	for(; first != last; first++)
		printf("%d ", *first);
	printf("\n");
}

// copies the range [first, last) into the range beginning at `dest`
// if the output range overlaps with [first, last), the behavior is undefined
// returns a pointer to the element past the last element copied
int* copy_int_range(const int* first, const int* last, int* dest)
{
	for(; first != last; first++, dest++)
		*dest = *first;
	return dest;
}

// merges the sorted ranges [first1, last1) and [first2, last2) into one sorted range beginning at `dest`
// both input ranges *must* be already sorted with respect to `cmp`, otherwise the output range is unspecified (and it will not be anything meaningful)
// if the output range overlaps with [first1, last1) or [first2, last2), the behavior is undefined
// returns a pointer to the element past the last element copied
int* merge_sorted_int_ranges(const int* first1, const int* last1, const int* first2, const int* last2, int* dest, int cmp(int, int))
{
	while(first1 != last1 && first2 != last2)
		if(cmp(*first1, *first2))
			*dest++ = *first1++;
		else
			*dest++ = *first2++;

	// at this point either first1 == last1 or first2 == last2, i.e. at least one of [first1, last1) and [first2, last2) is empty
	// therefore one of the next 2 calls of copy_int_range will do nothing and return immediately
	dest = copy_int_range(first1, last1, dest);
	dest = copy_int_range(first2, last2, dest);
	return dest;
}

int less(int a, int b)
{
	return a < b;
}

int main(void)
{
	unsigned size1, size2;
	scanf("%u%u", &size1, &size2);
	if(size1 > MAX_SZ || size2 > MAX_SZ)
	{
		printf("the largest supported size is %d\n", MAX_SZ);
		return 1;
	}

	int arr1[MAX_SZ], arr2[MAX_SZ];
	read_int_array(arr1, size1);
	read_int_array(arr2, size2);

	int merged[2 * MAX_SZ];
	int *merged_end = merge_sorted_int_ranges(arr1, arr1 + size1, arr2, arr2 + size2, merged, less);

	print_int_range(merged, merged_end);
	return 0;
}

/*
10 9
  1   2  3  4  4  5 12 17 22 23
-15 -13  2  3  5  6 13 14 20
*/