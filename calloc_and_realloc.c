// 9 Write a program to allocate memory using calloc( ) and then reallocate the previously allocated memory using realloc( ). Display the elements which have been taken after reallocation.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;
    int initial_size, new_size;
    // Get the initial size of the array
    printf("Enter the initial number of elements: ");
    scanf("%d", &initial_size);
    // Allocate memory using malloc
    arr = (int *)calloc(initial_size, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Input initial elements
    printf("Enter %d elements:\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Get the new size of the array
    printf("Enter the new number of elements: ");
    scanf("%d", &new_size);
    // Reallocate memory using realloc
    arr = (int *)realloc(arr, new_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Input additional elements if the size increased
    if (new_size > initial_size) {
        printf("Enter %d more elements:\n", new_size - initial_size);
        for (int i = initial_size; i < new_size; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }
    // Display all elements
    printf("The elements in the array are:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Free allocated memory
    free(arr);
    return 0;
}
