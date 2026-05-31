#include<stdio.h>

int missingNumber(int* nums, int numsSize){
    int expectedSum = 0, actualSum = 0;
    
    //calculate the expected sum of the list
    for(int i = 0; i < numsSize + 1; i++){
        printf("expected sum");
        expectedSum += i;
        printf("%d\n", expectedSum);
    }
    for(int i = 0; i < numsSize; i++){
        printf("actual sum");
        actualSum += nums[i];
        printf("%d\n", actualSum);
    }

    return expectedSum - actualSum;
}

//calculate the expected sum and actual sum of the number
int main(){
    int nums[] = {3, 0, 1};
    int numsSize = 3;
    int missing = missingNumber(nums, numsSize);
    printf("The missing number is %d", missing);
    return 0;
}