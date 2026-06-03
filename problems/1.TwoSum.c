#include<stdio.h>
#include<stdlib.h>

int* two_sum(int* nums, int numsSize, int target, int* returnSize){

    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                int* result = (int*)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;

                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}


int main(){
    int array[] = [2, 7, 11, 15];
    int arraySize = 4;
    int target = 9;
    int sizeOfResult = 0;

    
    printf("Indices are: %d and %d", two_sum(array, arraySize, target));
}