// 4 Write a program that reads two 2D metrices from the console, verifies if metrics multiplication is possible or not. Then multiplies the metrices and prints the 3rd metrics.
#include <stdio.h>
int main() {
    int rows1, cols1, rows2, cols2;
    // Read dimensions of the first matrix
    printf("Enter rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    // Read dimensions of the second matrix
    printf("Enter rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }
    // Declare matrices
    int mat1[rows1][cols1], mat2[rows2][cols2], result[rows1][cols2];
    // Input the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    // Input the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    // Initialize the result matrix to 0
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }
    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    // Print the result matrix
    printf("Resultant matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
return 0;
}