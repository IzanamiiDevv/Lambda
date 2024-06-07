#include <stdio.h>

// Define the function pointer type for the callback
typedef void (*func)(int);

void forEach(int arr[], int size, func cb) {
    for (int i = 0; i < size; i++) {
        cb(arr[i]);
    }
}

// Example callback function
void printElement(int element) {
    printf("%d\n", element);
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    void(*func[])(int) = {printElement};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);
    
    forEach(myArray, arraySize, printElement);
    
    return 0;
}