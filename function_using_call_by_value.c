// 2 Write a C program to pass an array to a function using Call by Value, update the array values in the function, print the array elements both in the function and in the calling function.
#include <stdio.h>
// Function to update the array
void updateArray(int arr[], int size) {
    printf("Inside the Function (Original Array):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Update the array
    for (int i = 0; i < size; i++) {
        arr[i] += 5;
    }
   printf("Inside the Function (Updated Array):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("In the main function (Original Array):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Call the function to update the array
    updateArray(arr, size);
    printf("In the main function (Updated Array):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
