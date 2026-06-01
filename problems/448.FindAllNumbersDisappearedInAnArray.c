#include <stdio.h>
#include <stdlib.h> // Fixed: Added for malloc and abs

int* findDisappearedNumbers(int* num, int numSize, int* returnSize){
    for(int i = 0; i < numSize; i++){
        int index = abs(num[i]) - 1;

        // Fixed: Flip positive numbers to negative
        if(num[index] > 0){
            num[index] = -num[index];
        }
    }

    int* result = (int*)malloc(sizeof(int) * numSize);
    int count = 0;

    for(int i = 0; i < numSize; i++){
        // If it's still positive, it means (i + 1) never appeared
        if(num[i] > 0){
            result[count] = i + 1; // Fixed: Use 'count' instead of 'i'
            count++;
        }
    }
    *returnSize = count; // Tell the caller how many elements are in the result
    return result;       // Fixed: Return the array pointer, not the count
}

int main(){
    // Fixed: Added [] bracket syntax
    int array[] = {1, 2, 5, 5, 3, 3, 7};
    int arraySize = 7;
    int sizeOfResult = 0; 
    
    // Fixed: Passed all 3 required arguments (including &sizeOfResult)
    int* result = findDisappearedNumbers(array, arraySize, &sizeOfResult);
    
    // Fixed: Only loop up to sizeOfResult, not arraySize
    for(int i = 0; i < sizeOfResult; i++){
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Clean up memory allocation
    return 0;
}