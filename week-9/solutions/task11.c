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

void rotateArray(int arr[], unsigned size, int rotations) {
    if(size <= 1)
        return;
    
    if (rotations > 0) {
        for (int r = 0; r < rotations; r++) {
            int last = arr[size - 1];
            for (int i = size - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = last;
        }
    }
    else {
        rotations = rotations < 0 ? -rotations : rotations;
        for (int r = 0; r < rotations; r++) {
            int first = arr[0];
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[size - 1] = first;
        }
    }
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
    printIntArray(intArray, size);

    int rotations;
    scanf("%d", &rotations);

    rotateArray(intArray, size, rotations);
    printIntArray(intArray, size);

    return 0;
}
