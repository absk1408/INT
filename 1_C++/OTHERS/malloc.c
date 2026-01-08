#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr;
    int initial_size = 3;
    int new_size = 5;

    // Step 1: Allocate initial memory
    arr = (int*)malloc(initial_size * sizeof(int));
    if (!arr) {
        printf("Initial malloc failed!\n");
        return 1;
    }

    // Fill initial array
    for (int i = 0; i < initial_size; i++) {
        arr[i] = i + 1;
    }

    // Print before realloc
    printf("Before realloc: ");
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 2: Resize memory
    int* temp = (int*)realloc(arr, new_size * sizeof(int));
    if (!temp) {
        printf("Realloc failed!\n");
        free(arr);  // Free original in case realloc failed
        return 1;
    }
    arr = temp;

    // Initialize new elements
    for (int i = initial_size; i < new_size; i++) {
        arr[i] = i + 1;
    }

    // Print after realloc
    printf("After realloc:  ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
