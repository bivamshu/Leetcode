#include<stdio.h>
#include<stdlib.h>

int* smallerNumberThanCurrent(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;

    int* result = malloc(numsSize * sizeof(int));

    if(result == NULL){
        return NULL;
    }
   
    for(int i = 0; i < numsSize; i++){
        int count = 0;
        for(int j = 0; j < numsSize; j++){
            if(nums[j] < nums[i]){
                count++;
            }
        }
        result[i] = count;
    }
    return result;
}


int main(){
    int numbers[] = {8, 1, 2, 2, 3};
    int numbersSize = 5;
    int returnSize = 0;

    int* ans = smallerNumberThanCurrent(numbers, numbersSize, &returnSize);

    printf("Result");
    for(int i = 0; i < returnSize; i++){
        printf("%d\n", ans[i]);
    }

    free(ans);

    return 0;
}