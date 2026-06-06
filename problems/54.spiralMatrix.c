#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    // Handle empty matrix edge case
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int totalElements = rows * cols;
    
    // Allocate memory for the 1D result array
    int* result = (int*)malloc(totalElements * sizeof(int));
    *returnSize = totalElements;

    // Initialize our four boundaries
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    
    int index = 0; // Tracks position in the result array

    while (top <= bottom && left <= right) {
        // 1. Move Right along the top row
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++; // Shrink the top boundary down

        // 2. Move Down along the right column
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--; // Shrink the right boundary left

        // 3. Move Left along the bottom row (Safety check required!)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--; // Shrink the bottom boundary up
        }

        // 4. Move Up along the left column (Safety check required!)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++; // Shrink the left boundary right
        }
    }

    return result;
}

// Helper code to test your solution locally
int main() {
    int rowSize = 3;
    int colSize = 3;
    int matrixColSize[] = {3, 3, 3};
    int returnSize = 0;

    // Allocate the mock 3x3 matrix
    int** matrix = malloc(rowSize * sizeof(int*));
    for (int i = 0; i < rowSize; i++) {
        matrix[i] = malloc(colSize * sizeof(int));
    }

    // Populate matrix: [[1,2,3],[4,5,6],[7,8,9]]
    int counter = 1;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            matrix[i][j] = counter++;
        }
    }

    // Execute Spiral Order
    int* ans = spiralOrder(matrix, rowSize, matrixColSize, &returnSize);

    // Print result
    printf("Spiral Order: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n"); // Expected Output: 1 2 3 6 9 8 7 4 5

    // Clean up memory
    free(ans);
    for (int i = 0; i < rowSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}