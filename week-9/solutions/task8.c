#include <stdio.h>
#define MAX_SIZE 1024

int readIntArray(int arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return size;
}

void printIntArray(const int arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}

int isSaw(const int arr[], unsigned size)
{
    if (size < 3)
        return 1;
    
    for (unsigned i = 0; i < size - 2; i++) {
        if ((arr[i] <= arr[i + 1] && arr[i + 1] <= arr[i + 2]) ||
            (arr[i] >= arr[i + 1] && arr[i + 1] >= arr[i + 2])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int intArray[MAX_SIZE];
    unsigned size;
    
    scanf("%u", &size);
    if(size > MAX_SIZE) {
        puts("Size should be less than 1025");
        return 1;
    }
    
    readIntArray(intArray, size);

    if(isSaw(intArray, size)) 
        puts("Array is a saw.");
    else puts("Array is not a saw.");

    return 0;
}