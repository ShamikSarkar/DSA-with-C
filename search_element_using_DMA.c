// 10 Write a C program to search an element in an Array using dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, searchElement, found = 0;
    int *arr;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &searchElement);

    // Search for the element in the array
    for (i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            printf("Element %d found at index %d\n", searchElement, i);
            found = 1;
            break; // Exit the loop once the element is found
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", searchElement);
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
