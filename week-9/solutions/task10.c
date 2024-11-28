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

int isPrime(int n) {
    if(n < 2)
        return 0;
    for (unsigned i = 2; i*i <= n; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

void removeElementAtIndex(int arr[], unsigned size, unsigned index) {
    for (unsigned i = index; i < size - 1; i++) {
            arr[j] = arr[j + 1];
        }
}

// There is a better way to remove numbers but this is more intuitive.
unsigned removeNumbersDivisibleBy5(int arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        if(arr[i] % 5 ==0) {
            removeElementAtIndex(arr, size, i);
            size--;
            // If we don't "i--;" we will go the the next element and skip it
            // {5, 25, 200, 56}
            // i = 0 we remove and then arr[i] becomes 25 and we skip it. 
            // This is why we "i--;" - on the next iteration we stay on the next element that is now the current one.
            i--;
        }
    }
    return size;
}

unsigned removeNumbersLessThan100(int arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        if(arr[i] < 100) {
            removeElementAtIndex(arr, size, i);
            size--;
            i--;
        }
    }
    return size;
}

unsigned removePrimeNumbers(int arr[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        if(isPrime(arr[i])) {
            removeElementAtIndex(arr, size, i);
            size--;
            i--;
        }
    }
    return size;
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

    size = removeNumbersDivisibleBy5(intArray, size);
    printIntArray(intArray, size);
    // or
    // size = removeNumbersLessThan100(intArray, size);
    // printIntArray(intArray, size);
    // or
    // size = removePrimeNumbers(intArray, size);
    // printIntArray(intArray, size);

    return 0;
}
