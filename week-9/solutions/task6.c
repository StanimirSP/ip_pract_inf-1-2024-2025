#include <stdio.h>
#define MAX_SIZE 1024

// Usually we don't want to put new lines in the char array. If you don't mind that just remove the if()
int readCharArray(char arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        scanf("%c", &arr[i]);
        if(arr[i] == '\n') {
            // If we don't i--; we will go the the next element. Better explanation to this logic in task10.c
            // Another example of how to do something like that below.
            i--;
        }
    }
    return size;
}

int readCharArray2(char arr[], unsigned size) {
    // We skip the i++ in the for loop
    for (unsigned i = 0; i < size; /**/ ) {
    //                            here
        scanf("%c", &arr[i]);
        if(arr[i] == '\n') {
            // We don't increase i if we have the `new line` charater.
            continue;
        }
    // And we do it here - at the end
        i++;
    }
    return size;
}

void printCharArray(const char arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        printf("'%c' ", arr[i]);
    }
    puts("");
}

int isLowerCaseLetter(char c) {
    if(c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

char toUpper(char c) {
    if(isLowerCaseLetter(c))
        return c - ('a' - 'A');
    return c;
}

void arrayToUpper(char arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        arr[i] = toUpper(arr[i]);
    }
}


int main() {
    char charArray[MAX_SIZE];
    unsigned size;
    scanf("%u", &size);
    if(size > MAX_SIZE) {
        puts("Size should be less than 1025");
        return 1;
    }

    readCharArray(charArray,size);
    printCharArray(charArray, size);

    arrayToUpper(charArray, size);
    printCharArray(charArray, size);
    
    return 0;
}
