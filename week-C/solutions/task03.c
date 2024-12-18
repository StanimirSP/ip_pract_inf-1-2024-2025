#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int extend_if_full(char** str, size_t* current_capacity, size_t current_size)
{
	if(current_size == *current_capacity)
	{
		char *extended = (char*)realloc(*str, *current_capacity * 2);
		if(!extended) return 0;
		*str = extended;
		*current_capacity *= 2;
	}
	return 1;
}

char* readline(size_t* ptr_sz, char delim)
{
	const size_t initial_capacitiy = 8;
	assert(initial_capacitiy > 1);
	char *str = malloc(initial_capacitiy);
	if(!str) return NULL;

	char ch;
	*ptr_sz = 0;
	size_t current_capacity = initial_capacitiy;
	while((ch = getchar()) != delim)
	{
		if(ch == EOF) // EOF was read before delim
			break; 	  // it is treated as delim
					  // we could have also treated this case as an error and returned NULL (after freeing str)

		if(!extend_if_full(&str, &current_capacity, *ptr_sz + 1)) // we use `*ptr_sz + 1` instead of `*ptr_sz` in order to guarantee free space for the null terminator at the end
		{
			free(str);
			return NULL;
		}
		str[(*ptr_sz)++] = ch;
	}
	str[*ptr_sz] = '\0';
	return str;
}

char* readline2(char delim)
{
	size_t size;
	return readline(&size, delim);
}

int main(void)
{
	char *str = readline2('\n');
	if(!str)
	{
		puts("readline failed");
		return 1;
	}

	printf("%s\n", str);

	free(str);
	return 0;
}