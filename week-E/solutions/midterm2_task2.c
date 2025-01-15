/*
Даден е символен низ с дължина не по-голяма от 1023 символа, който се прочита от стандартния вход. За край ще считамесимвола за нов ред.
За дума в текст ще считаме максимална по включване непрекъсната последователност, съставена само от цифри и латински букви.
Да се изведат уникалните думи в символния низ, като сравнението различава малки от главни букви. Редът на извеждане на думите не е от значение.
Да се изведе хистограма по дължината на низовете - за всяка дължина, да се изведат съответните думи и броят им. Хистограмата да бъде подредена по нарастване на дължината на думите. Редът на извеждане на думите с еднаква дължина не е от значение.

Пример:
Вход:
the quick brown fox jumped over the brown dog on the chair

Възможен изход:
the
quick
brown
fox
jumped
over
dog
on
chair

Хистограма по дължина:
2 - 1: on
3 - 3: the, fox, dog
4 - 1: over
5 - 3: quick, brown, chair
6 - 1: jumped

*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_SIZE 1023

typedef int (*Compare)(const void*, const void*);
void swap_byte(unsigned char* a, unsigned char* b);
void swap(void* a, void* b, size_t obj_size);
const void* min_element(const void* ptr, size_t count, size_t el_size, Compare cmp);
void selection_sort(void* ptr, size_t count, size_t el_size, Compare cmp);

int isValidWordSym(char ch) {
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z') ||
		(ch >= '0' && ch <= '9');
}

char* str_dup(const char* str)
{
	char* dup = malloc(strlen(str) + 1);
	if(!dup) return NULL;
	strcpy(dup, str);
	return dup;
}

void dealloc_words(char** words, size_t word_cnt)
{
	for(size_t i = 0; i < word_cnt; i++)
		free(words[i]);
	free(words);
}

char **splitWords(const char *text, const char* delims, size_t word_cnt) {
	char* text_copy = str_dup(text);
	if(!text_copy) return NULL;

	char** words = (char**)malloc(word_cnt * sizeof(char*));
	if(!words)
	{
		free(text_copy);
		return NULL;
	}

	char* token = strtok(text_copy, delims);
	size_t pos = 0;
	while(token)
	{
		words[pos] = (char*)malloc(strlen(token) + 1);
		if(!words[pos])
		{
			free(text_copy);
			dealloc_words(words, pos);
			return NULL;
		}
		strcpy(words[pos], token);
		pos++;
		token = strtok(NULL, delims);
	}

	free(text_copy);
	return words;
}


// this function is destructive. copy `text` if you need it
size_t countWords(char *text, const char* delims) {
	size_t word_cnt = 0;
	char* token = strtok(text, delims);
	while(token)
	{
		word_cnt++;
		token = strtok(NULL, delims);
	}
	return word_cnt;
}

char* delimiters(char* buffer)
{
	size_t pos = 0;
	for(char c = CHAR_MIN; c < CHAR_MAX; c++)
		if(c && !isValidWordSym(c))
			buffer[pos++] = c;
	if(!isValidWordSym(CHAR_MAX))
		buffer[pos++] = CHAR_MAX;
	buffer[pos] = '\0';
	return buffer;
}

int strcmp_len_lex(const void* str1, const void* str2)
{
	const char* a = *(const char**)str1;
	const char* b = *(const char**)str2;
	size_t len1 = strlen(a), len2 = strlen(b);
	if(len1 != len2)
		return len1 < len2;
	return strcmp(a, b) < 0;
}

/*int strcmp_len_lex_qsort(const void* str1, const void* str2)
{
	const char* a = *(const char**)str1;
	const char* b = *(const char**)str2;
	size_t len1 = strlen(a), len2 = strlen(b);
	if(len1 != len2)
		return (len1 > len2) - (len1 < len2);
	return strcmp(a, b);
}*/

void print_words(char** words, size_t word_cnt)
{
	for(size_t i = 0; i < word_cnt; i++)
		printf("%s\n", words[i]);
}

size_t unique_words(char** words, size_t word_cnt)
{
	size_t pos = 0;
	for(size_t i = 1; i < word_cnt; i++)
	{
		if(strcmp(words[pos], words[i]) == 0)
		{
			free(words[i]);
			words[i] = NULL;
		}
		else
			pos = i;
	}

	pos = 0;
	for(size_t i = 0; i < word_cnt; i++)
		if(words[i])
			words[pos++] = words[i];

	return pos;
}

void print_hist(char** words, size_t word_cnt)
{
	if(word_cnt < 1) return;
	size_t curr_len = strlen(words[0]);
	size_t curr_len_cnt = 1;
	for(size_t i = 1; i < word_cnt; i++)
	{
		if(curr_len == strlen(words[i]))
			curr_len_cnt++;
		else
		{
			printf("%zu - %zu:", curr_len, curr_len_cnt);
			for(size_t j = i - 1; curr_len_cnt--; j--)
				printf(" %s", words[j]);
			printf("\n");
			curr_len = strlen(words[i]);
			curr_len_cnt = 1;
		}
	}
	printf("%zu - %zu:", curr_len, curr_len_cnt);
	for(size_t j = word_cnt - 1; curr_len_cnt--; j--)
		printf(" %s", words[j]);
	printf("\n");
}

int main(void) {
	char str[MAX_SIZE + 1];
	scanf("%1023[^\n]", str);
	char delims[UCHAR_MAX + 2];
	delimiters(delims);
	char* str_copy = str_dup(str);
	if(!str_copy)
	{
		puts("failed to allocate memory");
		return 1;
	}
	size_t word_cnt = countWords(str_copy, delims);
	free(str_copy);
	char** words = splitWords(str, delims, word_cnt);
	if(!words)
	{
		puts("failed to allocate memory");
		return 1;
	}
	selection_sort(words, word_cnt, sizeof(char*), strcmp_len_lex);
	//qsort(words, word_cnt, sizeof(char*), strcmp_len_lex_qsort);

	word_cnt = unique_words(words, word_cnt);

	print_words(words, word_cnt);
	puts("===============");
	print_hist(words, word_cnt);

	dealloc_words(words, word_cnt);
	return 0;
}

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