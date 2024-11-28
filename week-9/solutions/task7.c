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

int hasNSumSubarray(const int arr[], unsigned size, int n) {
    for (unsigned i = 0; i < size; i++) {
        int sum = 0;
        for (unsigned j = i; j < size; j++) {
            sum += arr[j];
            // If you don't want the subarray to be k elements check (j - i != k - 1)
            if(sum == n) 
                // If you want to save the subarray it's the array from i to j because sum starts from i and ends in j.
                return 1;
        }
    }
    return 0;
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

    if(hasNSumSubarray(intArray, size, 0)) 
        puts("Array has subarray that sums to 0.");
    else puts("Array doesn't have subarray that sums to 0.");

    return 0;
}