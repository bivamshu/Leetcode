#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../data_structures/hashtable/hashtable.h"

int* two_sum(int* nums, int numsSize, int target, int* returnSize){
    //Brute Force method 
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

int* twoSumUsingHasmaps(int* nums, int numsSize, int target, int* returnSize){
    HashTable* ht = ht_create(numsSize);

    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++){
        int complement = target - nums[i];

        //Search the table for the complement
        void* found_index = ht_search(ht, complement);

        if(found_index != NULL){
            //Convert eh generic pointer back to an index
            result[0] = (int)(uintptr_t)found_index - 1; //Offset used to safely detect 0 index
            result[1] = i;
            *returnSize = 2;

            ht_free(ht);
            return result;
        }
        ht_insert(ht, nums[i], (void*)(uintptr_t)(i + 1));

    }
    ht_free(ht);
    free(result);
    return NULL;
}

int main(){
    int array[] = {2, 7, 11, 15};
    int arraySize = 4;
    int target = 9;
    int sizeOfResult = 0;

    int* indices = twoSumUsingHasmaps(array, arraySize, target, &sizeOfResult);

    if(indices != NULL){
        printf("Indices are: %d and %d\n", indices[0], indices[1]);
        free(indices);
    }
    else{
        printf("No solution found\n");
    }
    
    return 0;
}