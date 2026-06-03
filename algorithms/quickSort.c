#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *nums, int low, int high){
    int random_index = low + rand() % (high - low + 1);
    swap(&nums[random_index], &nums[high]);

    int pivot = nums[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(nums[j] <= pivot){
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i+1], &nums[high]);
    return i + 1;
}

void quickSort(int* nums, int low, int high){
    if(low < high){
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

void printArray(int *nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]); 
    }
    printf("\n");
}

int main(){
    // FIXED: Added [] here so it is properly recognized as an array
    int array[] = {1, 6, 5, 8, 9, 2, 4, 23, 22, 65, 23};
    int arraySize = 11;
    
    quickSort(array, 0, arraySize - 1); 
    printArray(array, arraySize);
    
    return 0;
}