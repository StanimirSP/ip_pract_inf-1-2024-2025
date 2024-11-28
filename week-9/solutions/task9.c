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

unsigned countPositiveNumbersInArray(const int arr[] , unsigned size) {
    unsigned count = 0;
    for (unsigned i = 0; i < size; i++) {
        if(arr[i] > 0)
            count++;
    }
    return count;
}

unsigned countEvenNumbersInArray(const int arr[] , unsigned size) {
    unsigned count = 0;
    for (unsigned i = 0; i < size; i++) {
        if(arr[i] % 2 == 0)
            count++;
    }
    return count;
}

unsigned countPrimeNumbersInArray(const int arr[] , unsigned size) {
    unsigned count = 0;
    for (unsigned i = 0; i < size; i++) {
        if(isPrime(arr[i]))
            count++;
    }
    return count;
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

    unsigned countPositive = countPositiveNumbersInArray(intArray, size);
    printf("There are %u positive numbers in this array.", countPositive);
    
    unsigned countEven = countEvenNumbersInArray(intArray, size);
    printf("There are %u even numbers in this array.", countEven);

    unsigned countPrime = countPrimeNumbersInArray(intArray, size);
    printf("There are %u prime numbers in this array.", countPrime);

    return 0;
}