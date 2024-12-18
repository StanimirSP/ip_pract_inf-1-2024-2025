#include <stdio.h>
#include <limits.h>

typedef int (*Compare)(const void*, const void*);

void swap_byte(unsigned char* a, unsigned char* b)
{
	unsigned char c = *a;
	*a = *b;
	*b = c;
}

void swap(void* a, void* b, size_t obj_size)
{
	for(unsigned char *p = a, *q = b; obj_size--; p++, q++)
		swap_byte(p, q);
}

const void* min_element(const void* ptr, size_t count, size_t el_size, Compare cmp)
{
	if(!count) return NULL;
	const void *p_min = ptr;
	for(const unsigned char *p = ptr; count--; p += el_size)
		if(cmp(p, p_min))
			p_min = p;
	return p_min;
}

void selection_sort(void* ptr, size_t count, size_t el_size, Compare cmp)
{
	for(unsigned char *p = ptr; count; p += el_size, count--)
		swap(p, (void*)min_element(p, count, el_size, cmp), el_size);
}

void print_ints(const int* arr, size_t sz)
{
	while(sz--)
		printf("%d ", *arr++);
	puts("");
}

int less_int(const void* a, const void* b)
{
	return *(const int*)a < *(const int*)b;
}

int main(void)
{
	int ints[] = {-2, 99, 0, -743, INT_MAX, 2, INT_MIN, 4};
	const int count = sizeof ints / sizeof * ints;

	selection_sort(ints, count, sizeof(*ints), less_int);
	print_ints(ints, count);

	return 0;
}
